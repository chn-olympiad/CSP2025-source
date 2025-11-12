#include<bits/stdc++.h>
using namespace std;
int T,n,cs[5];
bool yf[100005];
long long ans;
struct stu{
	int a,b,c;
};
stu ns[100005];
void dfs(long long now){
	ans=max(ans,now);
	for(int i=0;i<n;i++){
		if(!yf[i]){
			yf[i]=true;
			if(cs[0]<n/2){
				cs[0]++;
				dfs(now+ns[i].a);
				cs[0]--;
			}
			if(cs[1]<n/2){
				cs[1]++;
				dfs(now+ns[i].b);
				cs[1]--;
			}
			if(cs[2]<n/2){
				cs[2]++;
				dfs(now+ns[i].c);
				cs[2]--;
			}
			yf[i]=false;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(cs,0,sizeof(cs));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>ns[i].a>>ns[i].b>>ns[i].c;
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
