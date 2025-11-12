#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const bool ts=false;
int glt(int k){
	int a=1;
	while(a<k)a*=2;
	return a;
}
int f[2][1048999];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if(!ts){
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
	}
	//freopen("","w",stdout);
	int n,k,ans=0,m=-123456;
	cin>>n>>k;
	int a[n];
	bool ta=true;
	for(int i=0;i<n;++i){
		cin>>a[i];
		m=max(m,a[i]);
		if(a[i]!=1)ta=false;
	}
	m=glt(m);
	int ansf[n+1],dpa[n+1];
	for(int i=0;i<2;++i){
		for(int j=0;j<=m;++j){
			f[i][j]=99999999;
		}
	}
	for(int i=0;i<=n;++i){
		ansf[i+1]=99999999;
	}
	if(ta){
		cout<<n/2;
		return 0;
	}else{	
		f[0][a[0]]=0;
		ansf[0]=f[0][k];
		for(int i=1;i<n;++i){
			for(int j=0;j<=m;++j){
				if(a[i]==j)f[1][j]=i;
				else f[1][j]=f[0][j^a[i]];
			}
			if(f[1][k]!=99999999)ansf[f[1][k]]=min(ansf[f[1][k]],i);
			for(int j=0;j<=m;++j){
				f[0][j]=f[1][j];
			}
		}
	}
	for(int i=0;i<n;++i){
//		cout<<ansf[i]<<" ";
		dpa[i]=-1;
	}
//	cout<<endl;
	dpa[n]=0;
	for(int i=n-1;i>=0;--i){
		dpa[i]=dpa[i+1];
		if(ansf[i]>=0&&ansf[i]<n)dpa[i]=max(dpa[i],dpa[ansf[i]]+1);
		ans=max(ans,dpa[i]);
//		cout<<dpa[i]<<" ";
	}
//	cout<<endl;
	cout<<ans;
}