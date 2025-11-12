#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,s,a[N],c[N],cnt,ans;
struct node{
	int u,v;
}l[N];
bool cmp(node a,node b){
	return a.v<b.v;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		//cout<<c[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		int p=n+1;
		for(int j=i;j<=n;j++){
			if(c[j]==(k^c[i-1])){
				p=j;
				break;
			}
		}
		l[++cnt].u=i;
		l[cnt].v=p;
		//cout<<i<<p<<endl;
	}
	sort(l+1,l+cnt+1,cmp);
	int last=0;
	for(int i=1;i<=cnt;i++){
		if(l[i].v==n+1) break;
		if(l[i].u>last){
			ans++;
			last=l[i].v;
		}
	}
	cout<<ans;
	return 0;
}
