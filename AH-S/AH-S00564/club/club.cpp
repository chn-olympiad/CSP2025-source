#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
long long a[100005][5],b[100005][5],ans,c[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        b[0][1]=b[0][2]=b[0][3]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int choice=0;
            if(a[i][1]>a[i][2]){
                if(a[i][1]>a[i][3]){
                    choice=1;
                }else{
                    choice=3;
                }
            }else{
                if(a[i][2]>a[i][3]){
                    choice=2;
                }else{
                    choice=3;
                }
            }
            b[0][choice]++;
            b[b[0][choice]][choice]=i;
            ans+=a[i][choice];
        }
        /*
        for(int i=1;i<=b[0][1];i++){
            cout<<b[i][1]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=b[0][2];i++){
            cout<<b[i][2]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=b[0][3];i++){
            cout<<b[i][3]<<' ';
        }
        cout<<endl;
        */
        int big=0;
        if(b[0][1]>n/2) big=1;
        else if(b[0][2]>n/2) big=2;
        else if(b[0][3]>n/2) big=3;
        if(big==0){
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=b[0][big];i++){
            c[i]=0x3f3f3f3f;
            for(int j=1;j<=3;j++){
                if(j==big) continue;
                c[i]=min(a[b[i][big]][big]-a[b[i][big]][j],c[i]);
            }
        }
        /*
        for(int i=1;i<=b[0][big];i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
        */
        sort(c+1,c+b[0][big]+1);
        for(int i=1;i<=b[0][big]-n/2;i++){
            ans-=c[i];
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
