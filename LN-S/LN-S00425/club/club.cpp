#include<bits/stdc++.h>
using namespace std;

struct A{
    int a,b,c,z,z1;
    int zz,zz1;
}a[114514],b[51145];
bool cmp(A a,A b){
    return a.z>b.z;
}
bool cmp1(A a,A b){
    return (a.z-a.z1)<(b.z-b.z1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    bool f;
    cin>>t;
    while(t--){
        f=true;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].z=max(max(a[i].a,a[i].b),a[i].c);
            if(a[i].z==a[i].a)a[i].zz=1;
            if(a[i].z==a[i].b)a[i].zz=2;
            if(a[i].z==a[i].c)a[i].zz=3;
            a[i].z1=max(min(a[i].a,max(a[i].b,a[i].c)),min(a[i].b,max(a[i].a,a[i].c)));
            if(a[i].z1==a[i].a)a[i].zz1=1;
            if(a[i].z1==a[i].b)a[i].zz1=2;
            if(a[i].z1==a[i].c)a[i].zz1=3;
            if(a[i].b!=0||a[i].c!=0)fa=false;
        }

        sort(a,a+n,cmp);
        if(fa){
            int m=0;
            for(int i=0;i<n/2;i++){
                m+=a[i].a;
            }
        cout<<m;
        }
        int m1=0,m2=0,m3=0;
        int n1=0,n2=0,n3=0;
        for(int i=0;i<n;i++){
            if(a[i].zz==1){
                n1++;
                m1+=a[i].z;
                a[i].zz=0;
            }
            if(a[i].zz==2){
                n2++;
                m2+=a[i].z;
                a[i].zz=0;
            }
            if(a[i].zz==3){
                n3++;
                m3+=a[i].z;
                a[i].zz=0;
            }
        }
        if(n1>n/2){
            sort(a,a+n,cmp1);
            for(int i=0;i<n;i++){
                if(n1>n/2){
                    n1--;
                    m1-=a[i].z;
                    if(a[i].zz==2){
                        n2++;
                        m2+=a[i].z1;
                    }else{
                        n3++;
                        m3+=a[i].z1;
                    }
                }
                //cout<<n1<<m1<<n2<<m2<<n3<<m3;
            }
        }
        if(n2>n/2){
            sort(a,a+n,cmp1);
            for(int i=0;i<n;i++){
                if(n2>n/2){
                    n2--;
                    m2-=a[i].z;
                    if(a[i].zz==3){
                        n3++;
                        m3+=a[i].z1;
                    }else{
                        if(a[i].zz==1&&n1<n/2){
                            n1--;
                            m1-=a[i].z;
                        }
                    }
                }
                //cout<<n1<<m1<<n2<<m2<<n3<<m3;
            }
        }
        if(n3>n/2){
            sort(a,a+n,cmp1);
            for(int i=0;i<n;i++){
                if(n3>n/2){
                    n3--;
                    m3-=a[i].z;
                    if(a[i].zz==2&&n2<n/2){
                        n2++;
                        m2+=a[i].z1;
                    }else{
                        if(a[i].zz==1&&n1<n/2){
                            n1--;
                            m1-=a[i].z;
                        }
                    }
                }
                //cout<<n1<<m1<<n2<<m2<<n3<<m3;
            }
        }
        int m=m1+m2+m3;
        cout<<m<<endl;
    }
    return 0;
}

