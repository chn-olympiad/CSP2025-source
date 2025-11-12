#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int a[100005],b[100005],c[100005];
long long A=0,B=0,C=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
            if(a[j]>b[j]&&a[j]>c[j]){
				if(A+1<=n/2){
                    ans+=a[j];
                    A++;
				}
            }
            if(b[j]>a[i]&&b[j]>c[i]){
				if(B+1<=n/2){
                    ans+=b[j];
                    B++;
				}
			}
			if(c[j]>a[j]&&c[j]>b[j]){
				if(C+1<=n/2){
                    ans+=c[j];
                    C++;
				}
			}

		}
		cout<<ans<<endl;
		ans=0;
    }
    return 0;
}
