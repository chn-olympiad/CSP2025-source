#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][3],countt[3],maxn,ans,anss=0;
void dfs(int o){
	if(o==n){
		ans=max(ans,anss);
		return;
	}for(int i=0;i<3;i++){
		if(countt[i]+1<=maxn){
			countt[i]++;
			anss+=a[o][i];
			dfs(o+1);//WTF AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
			//cout<<o<<" "<<anss<<"fk\n";
			countt[i]--;
			anss-=a[o][i];
		}
	}return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>n;
		maxn=n/2;
		ans=0;
		anss=0;
		for(int i=0;i<3;i++){
			countt[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				//cout<<"ye\n";
			}//cout<<i<<"\n";
		}for(int i=0;i<3;i++){
			anss+=a[0][i];
			countt[i]++;
			dfs(1);
			countt[i]--;
			anss=0;
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
