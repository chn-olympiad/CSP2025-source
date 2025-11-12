#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
int n,ans,x,l=1,r=1,k,s[N],o,a[N];
map<int,int> c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	for (int i=2;i<=n;i++){
		s[i]=a[i]^s[i-1];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			x=s[j]^s[i-1];
			if(i==1) x^=0;
			if(x==k){
				if(c[i]) c[i]=min(c[i],j);
				else c[i]=j;
			}
		}
	}
	for (auto p:c){
		if(o){
			if (p.first>c[o]){
				o=p.first;
				ans++;
			}
		}
		else {
			o=p.first;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
