#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const mo=998244353;
int n,a[5005];
ll tot[25000005],ans;
struct aaa{
	int nm;
	ll s;
}; 
queue<aaa> q;
set<int> st; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	st.insert(a[1]+a[2]);tot[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		for(auto& j:st){
			if(j>a[i])ans=(ans+tot[j])%mo;
			q.push({j+a[i],tot[j]});
		}
		for(int j=1;j<i;j++){
			q.push({a[j]+a[i],1});
		}
		while(!q.empty()){
			st.insert(q.front().nm);
			tot[q.front().nm]+=q.front().s;
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}
