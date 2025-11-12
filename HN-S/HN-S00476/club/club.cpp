#include<bits/stdc++.h>
using namespace std;
struct club{
	int first,second,third;
};
int n,fi=0,se=0,th=0;
long long maxs=0;
struct club a[100010];
inline int dfs(int k,int ans){
	if(k == n){
		if(ans >= maxs) maxs = ans;	
		return 0;
	}
	if(fi<(n>>1)){
		fi++;
		dfs(k+1,ans+a[k].first);
		fi--;
	}
	if(se<(n>>1)){
		se++;
		dfs(k+1,ans+a[k].second);
		se--;
	}
	if(th<(n>>1)){
		th++;
		dfs(k+1,ans+a[k].third);
		th--;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		fi=0;se=0;th=0;maxs=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].first>>a[i].second>>a[i].third;
		}
		dfs(0,0);
		cout<<maxs<<endl;
	}
	return 0;
} 
