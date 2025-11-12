#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],b[100005],s[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=1;i<=100004;i++) b[i]=0;
        s[1]=s[2]=s[3]=0;
        cin>>n;
        long long num=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) cin>>a[i][j];
            if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]) s[3]++,b[i]=a[i][3]-max(a[i][2],a[i][1]),num+=a[i][3];
            else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]) s[2]++,b[i]=a[i][2]-max(a[i][3],a[i][1]),num+=a[i][2];
            else s[1]++,b[i]=a[i][1]-max(a[i][2],a[i][3]),num+=a[i][1];
        }
        sort(b+1,b+1+n);
        if(s[1]>n/2) for(int i=1;i<=s[1]-n/2;i++) num-=b[i];
        if(s[2]>n/2) for(int i=1;i<=s[2]-n/2;i++) num-=b[i];
        if(s[3]>n/2) for(int i=1;i<=s[3]-n/2;i++) num-=b[i];
        cout<<num<<endl;
    }
    return 0;
}
