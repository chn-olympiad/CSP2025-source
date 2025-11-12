#include<bits/stdc++.h>
using namespace std;
int a[5005],b[30];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    if(n<=27){
        while(b[28]==0){
            b[1]++;
            for(int i=1;i<=28;i++){
                if(b[i]==2)b[i]=0,b[i+1]++;
            }
            int co=0;
            for(int i=1;i<=28;i++)if(b[i])co++;
            if(co<3)continue;
            int sum=0,m=0;
            for(int i=1;i<=28;i++){
                sum+=a[i]*b[i];
                m=max(m,a[i]*b[i]);
            }
            if(sum>2*m)ans++;
        }
    }
    cout<<ans;
	return 0;
}
// ACPLS