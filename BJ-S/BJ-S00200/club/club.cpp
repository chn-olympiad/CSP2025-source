/*#include<bits/stdc++.h>
using namespace std;
int t,a1[15],b1[15],c1[15],a2,b2,c2,club;
int e[15];
int f(int n){
    int k ,ans;
    sort(a1,a1+n);
    sort(b1,b1+n);
    sort(c1,c1+n);
    if(a2>2/n){
        for(int i = 1;i<=n/2;i++){
             club+=a1[i];

        }
    }else{
        for(int i = 1;i<=a2;i++){
             club+=a1[i];
        }
    }
    for(int i = 1;i<=n;i++){
        k=max(e[i],e[i+1]);
    }
}
int main(){
    cin>>t;
    for(int i =1;i<=t;i++){
        int n;
        cin>>n;
        int a[15],b[15],c[15];
        a2=0;
        b2=0;
        c2=0;
        for(int j = 1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
            e[i]=max(a[i],b[i]);
            e[i]=max(e[i],c[i]);
            if(a[i]>=b[i]&&a[i]>=c[i]){
                a1[i]==e[i];
                a2++;
            }else if(b[i]>=a[i]&&b[i]>=c[i]){
                b1[i]==e[i];
                b2++;
            }else if(c[i]>=b[i]&&c[i]>=a[i]){
                c1[i]==e[i];
                c2++;
            }
        }
        f(n);
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int t;
int a[10005][3];
int main(){
    cin>>t;
    for(int i = 1;i<=t;i++){
        int n,ans,c1,c2,c3,b,c,d,e=0;
        cin>>n;
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=3;k++){
                cin>>a[j][k];
            }
        }
        int l = 1;
        for(int j = 1;j<=n;j++){
            for(l = 1;l<=3;l++){
                if(l==1){
                    ans=max(a[j][l],a[j][l-1]);
                    b=l;
                }
                if(l==2){
                    ans=max(a[j][l],a[j][l-1]);
                    c=l;
                }
                if(l==3){
                    ans=max(a[j][l],a[j][l-1]);
                    d=l;
                }

            }
            if(l==1){
                a[j][b]=0;
            }
            if(l==2){

                a[j][c]=0;
            }
            if(l==3){
                a[j][d]=0;
            }
        }
        if(n-3>=1){
            for(int j = 1;j<=2;j++){
                for(int l = 1;l<=3;l++){
                    if(a[j][j]!=0){
                        e+=a[j][l];
                    }
                }
            }
        }

        cout<<c1+c2+c3+e<<endl;
    }

    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int t;
int a[10005][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    if(t==1){
        int bbb;
            int x,y,z;
            cin>>x>>y>>z;
            if(x>y){
                bbb=x;
            }else{
                bbb=y;
            }
            if(bbb<z){
                bbb=z;
            }
        cout<<bbb<<endl;
        return 0;
    }
    if(t==2){
        int ans = 0;
        for(int i = 0;i<2;i++){
            int x,y,z;
            cin>>x>>y>>z;
            int bbb;
            bbb=max(x,y);
            bbb=max(bbb,z);
            ans+=bbb;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i = 1;i<=t;i++){
        int n,ans=0,b,c,d,e=0;
        cin>>n;
        for(int j = 1;j<=n;j++){
            for(int l = 1;l<=3;l++){
                cin>>a[j][l];
                if(a[j][l]>ans){
                    ans+=a[j][l];
                    a[j][l]=0;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}