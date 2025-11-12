#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n,a[N][4],ans;

void dfs(int i,int cl1,int cl2,int cl3,int sum){
	if(cl1 > n/2 || cl2 > n/2 || cl3 > n/2) return ;
	
	if(i>=n){
		ans = max(ans,sum);
		return ;
	}
	
	dfs(i+1,cl1+1,cl2,cl3,sum+a[i+1][1]);
	dfs(i+1,cl1,cl2+1,cl3,sum+a[i+1][2]);
	dfs(i+1,cl1,cl2,cl3+1,sum+a[i+1][3]);
}

bool cmp_b(pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
	return max(x.first,x.second.first) > max(y.first,y.second.first);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>t;
	while(t--){
		ans = 0;
	
		cin>>n;
		
		if(n > 100){
			vector<pair<int,pair<int,int> > > inp;
			inp.resize(n+1);
			
			for(int i = 1;i<=n;i++){
				cin>>inp[i].first>>inp[i].second.first>>inp[i].second.second;
			}
			
			inp.erase(inp.begin());
			
			sort(inp.begin(),inp.end(),cmp_b);
			int cl1 = 0,cl2 = 0;
			for(auto i : inp){
				if(i.first > i.second.first && cl1 < n/2){
					ans+=i.first;
					cl1++;
				}else if(i.first < i.second.first && cl2 < n/2){
					ans+=i.second.first;
					cl2++; 
				}else{
					if(cl1>cl2 && cl2 < n/2){
						ans+=i.second.first;
						cl2++;
					}else if(cl1 < n/2){
						ans+=i.first;
						cl1++; 
					}
				}
			}
			
			cout<<ans<<"\n";
			
			continue;
		}
		
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		dfs(0,0,0,0,0);
		
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
