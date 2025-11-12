#include<bits/stdc++.h>
using namespace std;
int t,n,maxn;
struct e{
	int b1;
	int b2;
	int b3;
}a[100010];
bool cmp(e kl,e kp){
	return kl.b1>kp.b1;
}
long long dfs(int cnt1,int cnt2,int cnt3,long long len,long long ans,int lenmax){
	//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<len<<" "<<ans<<" "<<lenmax<<endl;
	if(len==lenmax+1)return ans;
	if(cnt1>=maxn){
		if(cnt2>=maxn){
			return dfs(cnt1,cnt2,cnt3+1,len+1,ans+a[len].b3,lenmax);
		}
		if(cnt3>=maxn){
			return dfs(cnt1,cnt2+1,cnt3,len+1,ans+a[len].b2,lenmax);
		}
		return max(dfs(cnt1,cnt2+1,cnt3,len+1,ans+a[len].b2,lenmax),dfs(cnt1,cnt2,cnt3+1,len+1,ans+a[len].b3,lenmax));
	}
	if(cnt2>=maxn){
		if(cnt3>=maxn){
			return dfs(cnt1+1,cnt2,cnt3,len+1,ans+a[len].b1,lenmax);
		}
		return max(dfs(cnt1+1,cnt2,cnt3,len+1,ans+a[len].b1,lenmax),dfs(cnt1,cnt2,cnt3+1,len+1,ans+a[len].b3,lenmax));
	}
	if(cnt3>=maxn){
		return max(dfs(cnt1+1,cnt2,cnt3,len+1,ans+a[len].b1,lenmax),dfs(cnt1,cnt2+1,cnt3,len+1,ans+a[len].b2,lenmax));
	}
	return max(dfs(cnt1+1,cnt2,cnt3,len+1,ans+a[len].b1,lenmax),max(dfs(cnt1,cnt2+1,cnt3,len+1,ans+a[len].b2,lenmax),dfs(cnt1,cnt2,cnt3+1,len+1,ans+a[len].b3,lenmax)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		maxn=n/2;
		bool poi=1;
	//	long long ans1=0,ans2=0,ans3=0,cnt1=0,cnt2=0,cnt3=0;
	long long cnta=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
			if(a[i].b2!=0||a[i].b3!=0){
				poi=0;
			}
		}
		if(poi){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				cnta+=a[i].b1;
			}
			cout<<cnta<<endl;
			continue;
		}
		cout<<dfs(0,0,0,1,0,n)<<endl;
	}
}
// Ren5Jie4Di4Ling5%
