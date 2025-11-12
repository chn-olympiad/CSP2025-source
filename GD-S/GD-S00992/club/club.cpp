#include<bits/stdc++.h>
using namespace std;
int t,a[100005],b[100005],c[100005],n,ans;
struct point{
	int a,b,c;
}man[100005];
void dfs(int i,int ca,int cb,int cc,int sum){
	if(i==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(ca<n/2) dfs(i+1,ca+1,cb,cc,sum+a[i]);
	if(cb<n/2) dfs(i+1,ca,cb+1,cc,sum+b[i]);
	if(cc<n/2) dfs(i+1,ca,cb,cc+1,sum+c[i]);
	return ;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(b[i]!=0||c[i]!=0) return false;
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(c[i]!=0) return false;
	}
	return true;
}
bool cmp1(point a,point y){
	return a.a>y.a;
}
bool cmp2(point a,point y){
	return a.b>y.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(n<=20){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			ans=0;
		}else{
			if(check1()){
				sort(a+1,a+n+1);
				for(int i=n;i>=n/2;i++) ans+=a[i];
				cout<<ans<<endl;
			}else if(check2()){
				for(int i=1;i<=n;i++){
					man[i]={a[i],b[i],c[i]};
				}
				sort(man+1,man+n+1,cmp1);
				int ans1,ans2;
				ans1=ans2=0;
				for(int i=1;i<=n;i++){
					if(i<=n/2) ans1+=man[i].a;
					else ans1+=man[i].b;
				}
				sort(man+1,man+n+1,cmp2);
				for(int i=1;i<=n;i++){
					if(i<=n/2) ans2+=man[i].b;
					else ans2+=man[i].a;
				}
				cout<<max(ans1,ans2)<<endl;
			}
		}
	}
} 
