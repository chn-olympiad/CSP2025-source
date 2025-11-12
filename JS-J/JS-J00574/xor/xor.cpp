#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int ac[1001][1001],n;
int fzs(int x,int y,int z)
{
	if(x>n||y>n) return 0;
	if(ac[x][y]) return ac[x][y];
	int jy[21]={0};
	int zdws=0;
	int ans=0;
	for(int i=x;i<=y;i++){
		int ws=1,tds=a[i];
		while(tds){
			jy[ws]+=tds%2;
			if(jy[ws]>=2) jy[ws]=0;
			tds/=2;
			ws++;
		}
		if(ws>=zdws) zdws=ws;
	}
	for(int i=1;i<=zdws;i++){
		if(jy[i]){
			int ansf=1;
			for(int j=1;j<i;j++) ansf*=2;
			ans+=ansf;
		}
	}
	//cout<<x<<" "<<y<<" "<<ans<<endl;
	if(ans==z) return ac[x][y]=1+fzs(x+1,y+1,z);
	else{
		return ac[x][y]=max(fzs(x,y+1,z),fzs(x+1,y+1,z));
	}
	return 0;
}
int main()
{
	int k;
	cin>>n>>k;
	int tsd=0,tsd2=0;
	a.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) tsd++;
		if(a[i]==1) tsd2++;
	}
	if(k==0) cout<<tsd<<endl;
	else if(k==1) cout<<tsd2<<endl;
	else {
		int dyh=INT_MIN;
		for(int i=1;i<=n;i++){
		int fff=fzs(i,i,k);
		if(fff>=dyh) dyh=fff;
	}
		cout<<dyh;
	}
	return 0;
}
