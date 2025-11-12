#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n,t;
    cin>>t;
    while(t>0){
        t--;
        long long a[100005][3];
        long long b[100005];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n;
        //cout<<n<<endl;
        long long ans=0,s[3]={0,0,0};
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=0;i<n;i++){
            if(a[i][0]>=max(a[i][1],a[i][2]))s[0]++;
            if(a[i][1]>=max(a[i][2],a[i][0]))s[1]++;
            if(a[i][2]>=max(a[i][0],a[i][1]))s[2]++;
        }
        //cout<<s[0]<<s[1]<<s[2]<<endl;
        for(int i=0;i<n;i++){
            ans+=max(a[i][0],max(a[i][1],a[i][2]));
            //cout<<ans<<' ';
        }
        if(s[0]<=n/2&&s[1]<=n/2&&s[2]<=n/2){
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<3;i++){
            if(s[i]>n/2){
                for(int j=0;j<n;j++){
                    b[j]=a[j][i]-max(a[j][(i+1)%3],a[j][(i+2)%3]);
                    //cout<<b[j]<<' ';
                }
                sort(b,b+n);
                //for(int j=0;j<n;j++)cout<<b[j]<<' ';
                for(int j=0;s[i]>n/2;j++){
                    if(b[j]>=0){
                        ans-=b[j];
                        s[i]--;
                        //cout<<b[j]<<' ';
                    }
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
