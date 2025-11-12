#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
int n;
long long k;
struct node{
	int l,r;
}b[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	cin>>n>>k;
	int ans=0;
	int d=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]<=1)d++;
	}
	if(d==n){
		if(k==1){
			int c=0;
			for(int i=1; i<=n; i++){
				if(a[i])c++;
			}
			cout<<c;
		}else if(k==0){
			int c=0;
			for(int i=1; i<=n; i++){
				if(!a[i])c++;
			}
			cout<<c;
		}
		return 0;
	}
	long long x=0;
	for(int i=1; i<=n; i++){
		if(a[i]==k){
			b[++cnt].l=i,b[cnt].r=i;
		}
		x=a[i];
		int r=i;
		while(r<n){
			r++;
			x^=a[r];
			if(x==k){
				b[++cnt].l=i,b[cnt].r=r;
			}
		}
	}
	for(int i=1; i<=cnt; i++){
		for(int j=i+1; j<=cnt; j++){
			if(vis[i])continue;
			if((b[i].r<b[j].l)||(b[i].l>b[j].r)){
				continue;
			}else {
				vis[j]=1;
			}
		}
	}
	
	for(int i=1; i<=cnt; i++){
		if(!vis[i])ans++;
	}
	cout<<ans;
	return 0;
}
