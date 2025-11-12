#include <bits/stdc++.h>
using namespace std;
int n,t;
vector<pair<int,int> > v;
bool cmp(pair<int,int> a,pair<int,int> b) {return a.first>b.first;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		vector<int> a={0,0,0};
		for(int i=0,t,k=0;i<n;i++){
			for(int j=1;j<=3;j++){
				cin>>t;
				v.push_back({t,j});
			}
			sort(v.begin(),v.end(),cmp);

			while(1){
				if(a[v[k].second-1]<=n/2){
					a[v[k].second-1]++;
					ans+=v[k].first;
					break;
				}
				else k++;
			}

			v.clear();
		}
		cout<<ans;
		putchar('\n');
	}
	return 0;
}
