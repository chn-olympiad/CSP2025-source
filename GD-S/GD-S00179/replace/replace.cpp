#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s_1[2503],s_2[2503];
unsigned int hs_1[2503][2503],hs_2[2503][2503];
unsigned int hsx[2503];
int hsz=1000;
int si[2503];
int xl[2503];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s_1[i]>>s_2[i];
		si[i]=s_1[i].size();
		for(int j=1;j<=si[i];j++){
			hs_1[i][j]=hs_1[i][j-1]*hsz+(int)s_1[i][j-1];
			hs_2[i][j]=hs_2[i][j-1]*hsz+(int)s_2[i][j-1];
		}
	}
	xl[0]=1;
	for(int i=1;i<=2005;i++){
		xl[i]=xl[i-1]*hsz;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
		}else{
			int ans=0;
			unsigned int hsy=0;
			for(int j=1;j<=x.size();j++){
				hsx[j]=hsx[j-1]*hsz+(int)x[j-1];
				hsy=hsy*hsz+(int)y[j-1];
			}
			int xsi=x.size();
			for(int xu=1;xu<=n;xu++){
				for(int j=1;j<=xsi;j++){
					for(int k=j;k<=xsi;k++){
						for(int l=1;l<=si[xu];l++){
							for(int r=l;r<=si[xu];r++){
								if((hsx[k]-hsx[j-1])*xl[l]!=(hs_1[xu][r]-hs_1[xu][l-1])*xl[j])continue;
								if(hsx[xsi]-(hsx[k]-hsx[j-1])*xl[xsi-j]+(hs_2[xu][r]-hs_2[xu][l-1])*xl[xsi-j]!=hsy)continue;
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
