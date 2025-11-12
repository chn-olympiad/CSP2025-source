#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,s,t;
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]==k) ans++;
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			s=1;
			for (int o=i;o<=j;o++) s^=a[o];
			if (s==k) ans++;
		}
	cout<<ans;
	return 0;
}
