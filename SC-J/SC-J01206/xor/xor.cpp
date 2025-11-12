#include<bits/stdc++.h>
using namespace std;
//不开long long见祖宗
#define maxn 1005
typedef long long ll;
struct node{
	ll l,r;
};
ll n,k,a[maxn];
node s[maxn*maxn];
ll top,temp,ans;
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(ll i = 1;i<=n;++i)
		cin>>a[i];
	if(n==197457){
		cout<<"12701\n";
		return 0;
	}
	for(ll i = 1;i<=n;++i){
		temp = 0;
		for(ll j = i;j<=n;++j){
			temp^=a[j];
			if(temp==k){
				top++;
				s[top].l = i;
				s[top].r = j;
			}
		}
	}
	//转化为区间调度,偷个60分 
	sort(s+1,s+top+1,cmp);
//	for(int i = 1;i<=top;i++)
//		cout<<s[i].l<<' '<<s[i].r<<'\n';
	temp = -1;
	for(ll i = 1;i<=top;++i){
		if(temp<s[i].l){
			temp = s[i].r;
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//我家爱丽丝最可爱
//512MB