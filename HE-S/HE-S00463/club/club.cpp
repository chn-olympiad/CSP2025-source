#include<iostream>
#include<cstring>
using namespace std;
int t,n,s1,s2,s3,tot,ans;
bool use[100005];
int w1[100005],w2[100005],w3[100005];
void dfs(int id){
	if(id>n){
		ans=max(ans,tot);
		return ;
	}
	if(s1+1<=n/2){
		tot+=w1[id];
		s1++;
		dfs(id+1);
		s1--;
		tot-=w1[id];
	}
	if(s2+1<=n/2){
		tot+=w2[id];
		s2++;
		dfs(id+1);
		s2--;
		tot-=w2[id];
	}
	if(s3+1<=n/2){
		tot+=w3[id];
		s3++;
		dfs(id+1);
		s3--;
		tot-=w3[id];
	}
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		tot=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w1[i]>>w2[i]>>w3[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
