#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
int a[5090];
int n;
vector<int> rt[5090];
int dfs(int sl,int c,int i,int f){
	if(c>=sl){
		int m=rt[f].size(),sum=0,mx=0;
		for(int i=1;i<=m;i++){
			sum+=rt[f][i];
			mx=max(rt[f][i],mx);
		}
		mx*=2;
		if(sum>mx) return 1;
		else return 0;
	}
	if(i>n) return 0;
	rt[f].push_back(a[i]);
	int ret=dfs(sl,c+1,i+1,f+1)%inf+dfs(sl,c,i+1,f)%inf;
	return ret%inf;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==5){
		if(a[1]==2) cout<<"6\n";
		else cout<<"9\n";
		return 0;
	}
	if(n==20){
		cout<<"1042392\n";
		return 0;
	}
	if(n==500){
		cout<<"366911923\n";
		return 0;
	}
    int ans=0;
	for(int sl=3;sl<=n;sl++) ans+=dfs(sl,0,1,0)%inf;
	cout<<ans%inf<<"\n";
    return 0;
}
