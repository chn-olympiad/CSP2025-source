#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string p1[N],p2[N];
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>p1[i]>>p2[i];
	//for(int i=1;i<=n;i++)cout<<p1[i]<<' '<<p2[i]<<endl;
	//cout<<"-----------------------------\n";
	for(int i=1;i<=q;i++){
		ans=0;
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			//cout<<"-----------------------------\n";
			if(x.size()<p1[j].size())continue;
			for(int k=0;k<x.size()-p1[j].size();k++){
				//cout<<k<<endl;
				//cout<<"s"<<endl;
				int z=1;
				for(int l=k;l<k+p1[j].size();l++){
					if(x[l]!=p1[j][l-k]){
						z=0;
						break;
					}
				}if(z){
					//cout<<' '<<k<<endl;
					string w=x;
					for(int l=k;l<k+p2[j].size();l++){
						w[l]=p2[j][l-k];
					}if(w==y)ans++;
					//cout<<"  "<<ans<<endl;
				}//cout<<"e"<<endl;
			}
		}cout<<ans<<endl;
	}
	return 0;
}

