#include<bits/stdc++.h>
using namespace std;

int n;
int v[100005], w[100005];
int tmp[100005], T;
void Solve(){
	scanf("%d",&n);
	int c1=0,c2=0,c3=0;
	int ans=0;
	for (int i=1;i<=n;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		if (a==max({a,b,c})) v[i]=1, w[i]=a-max(b,c), c1++;
		else if (b==max({a,b,c})) v[i]=2, w[i]=b-max(a,c), c2++;
		else v[i]=3, w[i]=c-max(a,b), c3++;
		ans+=max({a,b,c});
	}
	if (max({c1,c2,c3})<=n/2) return printf("%d\n",ans), void();
	int flag;
	if (c1==max({c1,c2,c3})) flag=1;
	else if (c2==max({c1,c2,c3})) flag=2;
	else flag=3; T=0;
	for (int i=1;i<=n;i++)
		if (v[i]==flag) tmp[++T]=w[i];
	sort(tmp+1,tmp+T+1);
	for (int i=1;i<=T-n/2;i++) ans-=tmp[i];
	printf("%d\n",ans);
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; scanf("%d",&t);
	while (t--) Solve();
	return 0;
}
