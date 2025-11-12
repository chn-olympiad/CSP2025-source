#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,a[100005][3],ans,b[100005];
vector<vector<vector<int> > >f[100005];
//f[i][c1][c2][c3]:前i个人，c1人在第一部门，c2人在第二部门，c3人在第三部门，最大的满意值是多少
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        bool flag=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            b[i]=a[i][1];
            if(a[i][2]||a[i][3])flag=0;
        }
        if(flag){
            sort(b+1,b+1+n);
            for(int i=n/2+1;i<=n;i++)ans+=b[i];
        }else{
            for(int i=1;i<=n;i++){
                vector<vector<vector<int> > >v3;
                for(int c1=0;c1<=n/2&&c1<=i;c1++){
                    vector<vector<int> >v2;
                    for(int c2=0;c2<=n/2&&c1+c2<=i;c2++){
                        vector<int>v1;
                        int c3=i-c1-c2+1;
                        while(c3--){
                            v1.push_back(0);
                        }
                        v2.push_back(v1);
                    }
                    v3.push_back(v2);
                }
                f[i]=v3;
            }
            f[1][1][0][0]=a[1][1],f[1][0][1][0]=a[1][2],f[1][0][0][1]=a[1][3];
            for(int i=2;i<=n;i++){
                for(int c1=0;c1<=n/2&&c1<=i;c1++){
                    for(int c2=max(0,i-c1-n/2);c2<=n/2&&c1+c2<=i;c2++){
                        int c3=i-c1-c2;
                        if(c1>0){
                            f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1-1][c2][c3]+a[i][1]);
                            ans=max(ans,f[i][c1][c2][c3]);
                        }
                        if(c2>0){
                            f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2-1][c3]+a[i][2]);
                            ans=max(ans,f[i][c1][c2][c3]);
                        }
                        if(c3>0){
                            f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2][c3-1]+a[i][3]);
                            ans=max(ans,f[i][c1][c2][c3]);
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++)f[i].clear();
        }
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
}
