#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,k,mx;
int a[N],s[N];
struct node{
	int l,r;
};
vector<node> e;
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll sum=0;
			for(int q=i;q<=j;q++){
				sum^=a[q];
			}
			if(sum!=k)continue;
			e.push_back({i,j});
		}
	}
	sort(e.begin(),e.end(),cmp);
	int en=INT_MIN,ans=0;
	for(int i=0,len=e.size();i<len;i++){
		if(e[i].l>en){
			en=e[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
