#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long n,k,a[500010];
struct squ{
	int l,r;
}b[500010];
bool cmp(squ a,squ b){
	if(a.r==b.r)return a.l>b.l;
	else return a.r<b.r;
}
int main(){
	ios
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long x=a[i];
		b[i].l=i;
		b[i].r=-1;
		if(x==k){
			b[i].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				b[i].r=j;
				break;
			}
		}
		if(b[i].r==-1){
			b[i].l=-1;
			b[i].r=1e9;
		}
	}
	sort(b+1,b+n+1,cmp);
	if(b[1].l==-1){
		cout<<0;
		return 0;
	}
	int last=1,cnt=1;
	for(int i=2;i<=n;i++){
		if(b[i].l==-1)continue;
		if(b[i].l>b[last].r)++cnt,last=i;
	}
	cout<<cnt;
	return 0;
}
