#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,len,v[N],ans;
struct node{
	int l,r;
}b[N];
int cmp(node x,node y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.l>y.l;
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
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(t==k){
			b[++len].l=i;
			b[len].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			t^=a[j];
			if(t==k){
				b[++len].l=i;
				b[len].r=j;
				break;
			}
		}
	}
	sort(b+1,b+1+len,cmp);
	for(int i=1;i<=len;i++){
		int fl=0;
		for(int j=b[i].l;j<=b[i].r;j++){
			if(v[j]==1){
				fl=1;
				break;
			}
		}
		if(fl==0){
			ans++;
			for(int j=b[i].l;j<=b[i].r;j++){
				v[j]=1;
			}
		}
	}
	cout<<ans;
}
