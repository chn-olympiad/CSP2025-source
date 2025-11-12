#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}d[200005];
long long n,k,a[200005],x,l,r,s;
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			x=x^a[j];
			if(x==k){
				d[++l].l=i;
				d[l].r=j;
			}
		}
	}
	sort(d+1,d+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(d[i].l>r){
			s++;
			r=d[i].r;
		}
	}
	cout << s;
	return 0;
}
