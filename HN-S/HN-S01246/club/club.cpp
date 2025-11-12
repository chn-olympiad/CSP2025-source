#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6;
long long ans;
int n,t;
struct node{
	int num;
	int v;
}a[maxn],b[maxn],c[maxn];
map<int,bool> m1,m2,m3;
bool cmp(node x,node y){
	return x.v>y.v; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ans=0;
		for (int i=1;i<=n;i++){
			cin >> a[i].v >> b[i].v >> c[i].v;
			a[i].num=i,b[i].num=i,c[i].num=i;
			m1[i]=false,m2[i]=false,m3[i]=false;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int top1=0,top2=0,top3=0,k1=1,k2=1,k3=1;
		while (k1<=n&&k2<=n&&k3<=n){
			if (top1>=n/2) k1=n+1;
			if (top2>=n/2) k2=n+1;
			if (top3>=n/2) k3=n+1;
			while (m1[a[k1].num]||m2[a[k1].num]||m3[a[k1].num]) k1++;
			while (m1[b[k2].num]||m2[b[k2].num]||m3[b[k2].num]) k2++;
			while (m1[c[k3].num]||m2[c[k3].num]||m3[c[k3].num]) k3++;
			int v1=a[k1].v,v2=b[k2].v,v3=c[k3].v;
			if (v1>=v2&&v2>=v3){
				ans+=v1;
				m1[k1]=true;
				k1++;
				top1++;
			}else if (v2>=v1&&v1>=v3){
				ans+=v2;
				m2[k2]=true;
				k2++;
				top2++;
			}else{
				ans+=v3;
				m3[k3]=true;
				k3++;
				top3++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
