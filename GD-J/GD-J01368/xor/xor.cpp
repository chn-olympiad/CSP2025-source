#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,f,ans; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=1000) {
			for(int i=1;i<=n;i++) {
				f=0;
				for(int j=i;j<=n;j++){
					f^=a[j];
					if(f==m) {
						ans++;
						i=j;
						break;
					}
				}
			
		}
		cout<<ans;
	}
	else {
		l=1,r=1;
		while(l<=r&&r<=n) {
			f^=a[r];
			while(l<r&&f>m) f^=a[l++];
			r++;
			if(f==m) {
				ans++;	
				l=r;
				f=0;
			
			}
			
		}
		cout<<ans;
	}
	return 0;
}

