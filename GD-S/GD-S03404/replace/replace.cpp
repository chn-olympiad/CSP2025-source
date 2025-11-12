#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
const int N=1000005;
int n,q;
string u[N],v[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<a.size();j++){
				string h;
				for(int k=i;k<=j;k++){
					h+=a[k]; 
				}
				
				for(int k=1;k<=n;k++){
					if(h==u[k]){
//						cout<<h<<endl;
						string hh;
						for(int ii=0;ii<i;ii++){
							hh+=a[ii];
						}
						hh+=v[k];
						for(int jj=j+1;jj<a.size();jj++){
							hh+=a[jj];
						}
//						cout<<hh<<endl; 
						if(hh==b){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
