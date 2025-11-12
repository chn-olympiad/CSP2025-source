#include<bits/stdc++.h>
using namespace std;
const int N=2000;
long long n,m,s=1,ans;
string q[N][3];
string zc[N];
string th[N];
vector<pair<int,int> > st; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i][1]>>q[i][2];
	}
	for(int i=1;i<=n;i++){
		cin>>zc[i]>>th[i];
	}
	while(s){
		if(s>m)break;
		for(int i=1;i<=n;i++){
			st.clear();
			for(int j=0;j<q[s][1].size();j++){
				if(q[s][1][j]==zc[i][0]){
					for(int k=1;k<zc[i].size();k++){
						if(q[s][1][j+k]!=zc[i][k]){
							break;
						}
						if(k==zc[i].size()-1){
							st.push_back({j,i});
						}
					}				
				}

			}
			for(int i=0;i<st.size();i++){
				string h=q[s][1];
				int ppp=0;
				for(int j=st[i].first;j<st[i].first+zc[st[i].second].size();j++){
					h[j]=th[st[i].second][ppp];
					ppp++;
				}
				if(h==q[s][2])ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
		s++;
	}
}
