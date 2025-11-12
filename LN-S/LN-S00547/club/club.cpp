#include<bits/stdc++.h>
using namespace std;
int t,n,s[5];
int a[11][5],mx[11],m[11],mi[11],ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++){
        s[1]=0,s[2]=0,s[3]=0;
        ans=0;
        scanf("%d",&n);
        int w=n/2;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2] and a[i][2]>=a[i][3]){
                mx[i]=1;
                m[i]=2;
                mi[i]=3;
            }
            else if(a[i][1]>=a[i][3] and a[i][3]>=a[i][2]){
                mx[i]=1;
                m[i]=3;
                mi[i]=2;
            }
            else if(a[i][2]>=a[i][1] and a[i][1]>=a[i][3]){
                mx[i]=2;
                m[i]=1;
                mi[i]=3;
            }
            else if(a[i][2]>=a[i][3] and a[i][3]>=a[i][1]){
                mx[i]=2;
                m[i]=3;
                mi[i]=1;
            }
            else if(a[i][3]>=a[i][1] and a[i][1]>=a[i][2]){
                mx[i]=3;
                m[i]=1;
                mi[i]=2;
            }
            else{
                mx[i]=3;
                m[i]=2;
                mi[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(s[mx[i]]<w){
                ans+=a[i][mx[i]];
                s[mx[i]]++;
            }
            else{
                int mxn=-100,wz;
                for(int j=1;j<=n;j++){
                    if(mx[j]!=mx[i]){
                        continue;
                    }
                    if(mxn<(a[i][mx[i]]-a[j][mx[j]]-a[j][mx[j]]+a[j][m[j]])){
                            mxn=a[i][mx[i]]-a[j][mx[j]]-a[j][mx[j]]+a[j][m[j]];
                            wz=j;
                    }
                }
                if(mxn>=0){
                    ans+=mxn+a[wz][mx[wz]];
                    mx[wz]=m[wz];
                    m[wz]=mi[wz];
                }
                else{
                    int sz=0;
                    for(int j=1;j<=n;j++){
                        if(mx[j]!=mx[i]){
                        continue;
                        }
                        if((a[i][mx[i]]+a[j][m[j]])>(a[j][mx[j]]+a[i][m[i]]) and (a[i][mx[i]]+a[j][m[j]])>sz){
                                sz=a[i][mx[i]]+a[j][m[j]]-a[j][mx[j]];
                        }
                    }
                    if(sz!=0)ans+=sz;
                    else ans+=a[i][m[i]];
                }
            }
        }
        cout<<ans<<endl;
    }
}

