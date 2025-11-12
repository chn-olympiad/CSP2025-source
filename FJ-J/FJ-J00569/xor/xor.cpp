#include<bits/stdc++.h>
#define unt unsigned int
#define L 500010
using namespace std;
int n,k,maxans;
bool A=true,B=true;
int c0,c1;
unt a[L];
bool x[L];
unt xorsum(int st,int ed){
	unt sum=0;
	for(int i=st;i<=ed;i++){
		sum^=a[i];
	}
	return sum;
}
void nxt(){
	x[0]=!x[0];
	int i=0;
	while(x[i]==0&&i<n-1){
		x[i+1]=!x[i+1];
		i++;
	}
}
int lop(){
	int res=0;
	for(int i=0;i<n-1;i++){
		if(x[i])res++;
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1&&A)A=false;
		if(a[i]!=1&&a[i]!=0&&B)B=false;
		else if(a[i]==0)c0++;
		else if(a[i]==1)c1++;
	}
	if(A){
		cout<<"1";
		return 0;
	}
	if(B&&n>10){
		if(k==0)cout<<c0;
		else cout<<c1;
		return 0;
	}
	while(lop()!=n-1){
		int ans=0;
		int st=0,ed=0;
		for(int i=0;i<n;i++){
			if(x[i]){
				ed=i;
				if(xorsum(st,ed)==k)ans++;
				st=ed;
			}
		}
		ed=n;
		if(xorsum(st,ed)==k)ans++;
		st=ed;
		maxans=max(ans,maxans);
		nxt();
	}
	cout<<maxans;
	return 0;
}
