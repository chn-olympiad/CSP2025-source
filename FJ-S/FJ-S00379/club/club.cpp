#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	int a[100005],b[100005],c[100005];
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i]>>b[i]>>c[i];
	    }
	    int cnt=0;
	    int a1=n/2,b2=n/2,c3=n/2;
	    for(int i=1;i<=n;i++){
	        if(a1&&a[i]>=b[i]&&a[i]>=c[i]){
	        	cnt+=a[i];
	        	a1--;
			}else if(b2&&b[i]>=a[i]&&b[i]>=c[i]){
				cnt+=b[i];
				b2--;
			}else{
				cnt+=c[i];
				c3--;
			}
		}
	}
    return 0;
}
