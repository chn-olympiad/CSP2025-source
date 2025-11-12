#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,num=0,c=0,r=0,a[105]={0};
bool flag=true;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(long long i=1;i<=cnt;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==num){
		cout<<1<<' '<<1;
		return 0;
	}
	c=1,r=1;
	for(long long i=2;i<=cnt;i++){
		if(flag==true){
			if(r<n) r++;
			else flag=false,c++;
		} else if(flag==false){
			if(r>1) r--;
			else flag=true,c++;
		}
		if(a[i]==num){
			cout<<c<<' '<<r;
			return 0;
		}
	}
	return 0;
}