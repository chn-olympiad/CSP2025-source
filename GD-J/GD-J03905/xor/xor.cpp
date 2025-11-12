#include<bits/stdc++.h>
using namespace std;
int chec[1100000];
int vec[1100000];
int ans[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int s[n+1];
	memset(s,-1,sizeof(s));
	s[0]=0;
	memset(chec,-1,sizeof(chec));
	memset(vec,-1,sizeof(vec));
	memset(ans,0,sizeof(ans));
	chec[0]=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];//cout<<(s[i]^k)<<' ';
		
		
		if(chec[s[i]^k]>=0){
			vec[i]=chec[s[i]^k];
		}
		chec[s[i]]=i;
		//cout<<vec[i]<<' ';
	}
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		if(vec[i]!=-1)
			ans[i]=max(ans[vec[i]]+1,ans[i-1]);
		else
			ans[i]=ans[i-1];
		//cout<<ans[i]<<' ';
	}
	cout<<ans[n];
	return 0;
}
