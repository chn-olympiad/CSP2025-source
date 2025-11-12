#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,ans;
int a[N],s[1005][1005];
bool v[N];
struct node{
	int l,r,cz;
}t[N];
bool cmp(node a,node b){
	if(a.cz!=b.cz)return a.cz<b.cz;
	else if(a.l!=b.l)return a.l<b.l;
	else return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1000){
		for(int i=1;i<=n;i++)s[i][i]=a[i];
		for(int i=2;i<=n;i++)s[1][i]=s[1][i-1]^s[i][i];
		for(int i=2;i<n;i++){
			for(int j=i+1;j<=n;j++){
				s[i][j]=s[1][j]^s[1][i-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(s[i][j]==k){
					t[++cnt].l=i;
					t[cnt].r=j;
					t[cnt].cz=abs(i-j);
				}
			}
		}
		sort(t+1,t+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			bool flag=0;
			for(int j=t[i].l;j<=t[i].r;j++){
				if(v[j])flag=1;	
			}
			if(flag)continue;
			ans++;
			for(int j=t[i].l;j<=t[i].r;j++)v[j]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
