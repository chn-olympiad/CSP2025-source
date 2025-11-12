#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n;
long long k;
long long a[N];
long long he[N];
int cnt=0;
int mk[N];
int tot;
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	for(;x<=n;x+=lowbit(x))
		mk[x]+=1;
	return ;
}
int ser(int x){
	int res=0;
	for(;x>0;x-=lowbit(x))
		res+=mk[x];
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int shu1=0,shu0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		he[i]=he[i-1]^a[i];
		if(a[i]==1) shu1++;
		if(a[i]==0) shu0++;
	}
	if(shu1+shu0==n){
		if(k==1) cout<<shu1;
		else if(k==0) cout<<shu0;
		return 0;
	}
	tot=n;
	for(int i=1;i<=n;i++){
		if(tot<i) break;
		for(int j=1;j<=n;j++){
			if(mk[j]==2||mk[j+i-1]==2) continue;
			if(ser(j+i-1)-ser(j-1)>0) continue;
			int x=he[j-1]^he[j+i-1];
			if(x==k){
				cnt++;
				add(j);
				if(i>1)
					add(j+i-1);
				tot-=i;
			}
		}
	}
	cout<<cnt;
	return 0;
} 