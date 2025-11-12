#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],aa,bb,cc,an,bn,cn;
struct node{
    int p1,p2,p3;
}m[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        //cout<<"------------"<<t<<"-------------"<<endl;
        aa=bb=cc=0;
        an=bn=cn=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=max(b[i],c[i])){
                m[i].p1=1;
                if(b[i]>=c[i]){
                    m[i].p2=2;
                    m[i].p3=3;
                }else{
                    m[i].p2=3;
                    m[i].p3=2;
                }
            }else if(b[i]>=max(a[i],c[i])){
                m[i].p2=1;
                if(a[i]>=c[i]){
                    m[i].p1=2;
                    m[i].p3=3;
                }else{
                    m[i].p1=3;
                    m[i].p3=2;
                }
            }else{
                m[i].p3=1;
                if(a[i]>=b[i]){
                    m[i].p1=2;
                    m[i].p2=3;
                }else{
                    m[i].p1=3;
                    m[i].p2=2;
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<m[i].p1<<m[i].p2<<m[i].p3<<endl;
        }*/
        for(int i=1;i<=n;i++){
            if(m[i].p1==1){
                if(an<n/2){
                    aa+=a[i];
                    an++;
                    //cout<<"aa+++"<<a[i]<<" ";
                }else{
                    if(m[i].p2==2&&bn<n/2){
                        bb+=b[i];
                        bn++;
                    }else{
                        cc+=c[i];
                        cn++;
                    }
                }
            }else if(m[i].p2==1){
                if(bn<n/2){
                    bb+=b[i];
                    bn++;
                }else{
                    if(m[i].p1==2&&an<n/2){
                        aa+=a[i];
                        an++;
                    //cout<<"aa+++"<<a[i]<<" ";
                    }else{
                        cc+=c[i];
                        cn++;
                    }
                }
            }else{
                if(cn<n/2){
                    cc+=c[i];
                    cn++;
                }else{
                    if(m[i].p1==2&&an<n/2){
                        aa+=a[i];
                        an++;
                    //cout<<"aa+++"<<a[i]<<" ";
                    }else{
                        bb+=b[i];
                        bn++;
                    }
                }
            }
        }
        //cout<<an<<" "<<bn<<" "<<cn<<" "<<endl;
        cout<<aa+bb+cc<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
