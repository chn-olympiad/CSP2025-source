#include<bits/stdc++.h>
using namespace std;
int T;
int n;
vector<int> v1,v2,v3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		v1.clear();
		v2.clear();
		v3.clear();
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(max(a,max(b,c))==a){
				v1.push_back(a-max(b,c));
				ans+=a;
			}
			else if(max(a,max(b,c))==b){
				v2.push_back(b-max(a,c));
				ans+=b;
			}
			else{
				v3.push_back(c-max(a,b));
				ans+=c;
			}
		}
		if(v1.size()>n/2){
			sort(v1.begin(),v1.end());
			for(int i=0;i<v1.size()-n/2;i++) ans-=v1[i];
		}
		if(v2.size()>n/2){
			sort(v2.begin(),v2.end());
			for(int i=0;i<v2.size()-n/2;i++) ans-=v2[i];
		}
		if(v3.size()>n/2){
			sort(v3.begin(),v3.end());
			for(int i=0;i<v3.size()-n/2;i++) ans-=v3[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
