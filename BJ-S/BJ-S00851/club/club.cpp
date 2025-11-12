#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ull n;
        cin>>n;
        ull zd=n/2;
        ull a[100005],b[100005],c[100005],aa=0,bb=0,cc=0,sum=0,da[50005],db[50005],dc[50005];
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            if(max(a[i],max(b[i],c[i]))==a[i]){
                sum+=a[i];
                aa++;
                da[aa]=a[i]-max(b[i],c[i]);
                if(aa>zd){
                    aa--;
                    ull zxc,zxci;
                    for(int j=1;j<=aa;j++){
                        if(zxc<da[j]){
                            zxc=da[j];
                            zxci=j;
                        }
                        sum=sum-a[zxci];
                        sum=sum+a[zxc]-zxc;
                    }
                }
            }
            if(max(a[i],max(b[i],c[i]))==b[i]){
                sum+=b[i];
                bb++;
                db[bb]=b[i]-max(a[i],c[i]);
                if(bb>zd){
                    bb--;
                    ull zxc,zxci;
                    for(int j=1;j<=bb;j++){
                        if(zxc<db[j]){
                            zxc=db[j];
                            zxci=j;
                        }
                        sum=sum-b[zxci];
                        sum=sum+b[zxc]-zxc;
                    }
                }
            }
            if(max(a[i],max(b[i],c[i]))==c[i]){
                sum+=c[i];
                cc++;
                dc[cc]=c[i]-max(a[i],b[i]);
                if(cc>zd){
                    cc--;
                    ull zxc,zxci;
                    for(int j=1;j<=cc;j++){
                        if(zxc<dc[j]){
                            zxc=dc[j];
                            zxci=j;
                        }
                        sum=sum-c[zxci];
                        sum=sum+c[zxc]-zxc;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
