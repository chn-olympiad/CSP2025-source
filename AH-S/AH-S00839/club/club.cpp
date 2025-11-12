#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}a[100005];
int n;
bool cmp(node a,node b){
	return a.x>b.x;
}
int dfs(int i,int ans,int q1,int w1,int e1){
	if(i==n+1)return ans;
	int a1=0,a2=0,a3=0;
	if(q1<n/2)a1=dfs(i+1,ans+a[i].x,q1+1,w1,e1);
	if(w1<n/2)a2=dfs(i+1,ans+a[i].y,q1,w1+1,e1);
	if(e1<n/2)a3=dfs(i+1,ans+a[i].z,q1,w1,e1+1);
	return max({a1,a2,a3});
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
		long long q1=0,q2=0,q3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            q1+=a[i].x;q2+=a[i].y;q3+=a[i].z;
        }
        if(q2==0 && q3==0){
			sort(a+1,a+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}
		else {
			cout<<dfs(1,0,0,0,0)<<endl;
		}
    }
    return 0;
}
