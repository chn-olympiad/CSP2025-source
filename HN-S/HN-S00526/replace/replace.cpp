#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,k;
string a[N][2];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(k--){
		int ans=0;
		string q,w,qf;
		cin>>q>>w;
		for(int i=1;i<=n;i++){
			if(a[i][1].size()<=q.size()){
				for(int j=0;j<=q.size()-a[i][1].size();j++){
					qf=q;
					int l=1;
					for(int h=0;h<a[i][1].size();h++){
						if(a[i][1][h+j]!=q[h+j]){
							l=0;
							break;
						}
					}
					if(l==0){
						continue;
					}
					for(int h=0;h<a[i][1].size();h++){
						qf[h+j]=a[i][2][h+j];
					}
					if(qf==w){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

