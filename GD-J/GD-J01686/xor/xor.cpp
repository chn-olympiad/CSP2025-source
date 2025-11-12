#include<bits/stdc++.h>
using namespace std;
long long n,k,t,w,sum,mi;int a[10000000];
struct o{
	long long l;
	long long r;
}q[5000000];
bool cmp(o x,o y) {
	if(x.r<y.r){
		return true;
	}
	else return false;
}
int main(){
	freopen("xor,in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		t=a[i];
		if(t==k){
			q[w].l=i;q[w++].r=i;
			continue;
			}
		for(long long j=i+1;j<=n;j++){
			t=(t)xor(a[j]);
			if(t==k){
				q[w].l=i;q[w++].r=j;
				break;
			}
		}
	}
	sort(q,q+w,cmp);if(q[0].l!=0) sum++;
	mi=q[0].r;
	for(long long i=1;i<=n;i++){
		if(q[i].l<=mi){
			continue;
		}
		else{
			sum++;
			mi=q[i].r;
		}
	}
	cout<<sum;
	return 0;
}
