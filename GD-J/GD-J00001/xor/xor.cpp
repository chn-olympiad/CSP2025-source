#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int idx[1100005];
int maxa[500005];
int n,k;
int ans=0;
int ch(int x,int tt){
	int y=x;
	int anss=0;
	int an[25]={};
	int i=0;
	while(y||tt){
		i++;
		if(tt%2==0)an[i]=y%2;
		else an[i]=1-y%2;
		y/=2,tt/=2;
	}
	for(int j=i;j>=1;j--)anss*=2,anss+=an[j];
	return anss;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=(b[i-1]^a[i]);
	idx[0]=0;
	for(int i=1;i<=n;i++){
		idx[b[i]]=i;
		int flag=1;
		int t=ch(b[i],k);
		int ttt=0;
		if(t!=0&&idx[t]==0)flag=0;
		if(flag==1)ttt=maxa[idx[t]]+1;
		maxa[i]=max(maxa[i-1],ttt);
	}
	cout<<maxa[n];
	return 0;
} 
