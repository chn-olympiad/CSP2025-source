#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],c[1000010],a1,b1,c1,ans;
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdin);
	int t,n;
	cin>>t;
	while(t--){
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=c[i]&&a[i]>=b[i]&&a1<n/2){
				a1++;
				ans+=a[i];
			}
			else if(b[i]>=c[i]&&b[i]>=a[i]&&b1<n/2){
				b1++;
				ans+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]&&c1<n/2){
				c1++;
				ans+=c[i];
			}
		}
	}
	return 0;
}
