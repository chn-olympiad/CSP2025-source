#include<bits/stdc++.h>
using namespace std;
int n,a[500005],s[500005],ans=0;
long long k;
struct lr{
	int l,r;
}qu[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int p=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long u=s[i-1]^s[j];
			if(u==k){
				qu[p].l=i;
				qu[p].r=j;
				p++;
			}
		}
	}
	int mr=0;
	for(int i=1;i<p;i++){
		if(qu[i].l>mr){
			ans++;
			mr=qu[i].r;
		}
	}
	cout<<ans;
	return 0;
}
