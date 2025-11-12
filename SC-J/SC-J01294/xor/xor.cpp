#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans;
int cnt=1;
struct node{
	int l,r;
}b[500001];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int res=a[i];
		if(k==a[i]){
			b[cnt].l=i;
			b[cnt].r=i;
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			res=res^a[j];
			if(res==k){
				b[cnt].l=i;
				b[cnt].r=j;
				cnt++;
				break;
			}
		}
	}
	sort(b+1,b+cnt,cmp);
	int last=0;
	for(int i=1;i<cnt;i++){
		if(last<b[i].l){
			last=b[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 