#include <bits/stdc++.h>
using namespace std;
int n,ans;
int l[5005];
long long ll[5005];
bool a[5005];
void f(int maxn,int sum,int q,int p1,int p2,bool b[]){
	if(q==0&&sum>maxn*2) ans++;
	if(p2-p1<q) return;
	if(p1!=0){
		if(sum+ll[p2]-ll[p1-1]<=maxn*2) return;
	}
	for(int i=p1;i<p2;i++){
		if(b[i]==0){
			b[i]=1;
			f(maxn,sum+l[i],q-1,i,p2,b);
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>l[i];
	sort(l,l+n);
	for(int i=0;i<n;i++){
		if(i==0) ll[i]=l[i];
		ll[i]=ll[i-1]+l[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=i-1;j<n;j++){
			f(l[j],l[j],i-1,0,j,a);
		}
	}
	cout<<ans;
	return 0;
} 
