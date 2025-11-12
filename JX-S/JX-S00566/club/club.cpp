#include<iostream>
#include<algorithm>
using namespace std;
struct yg{
    int a,b,c,acnt,bcnt,ccnt,idx;
}a[100005],t[100005];
bool cmpa(yg a,yg b){
    return a.a>b.a;
}
bool cmpb(yg a,yg b){
    return a.b>b.b;
}
bool cmpc(yg a,yg b){
    return a.c>b.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,an=0,bn=0,cn=0,cnt=0;
        long long sum=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i].a,&a[i].b,&a[i].c);
            a[i].idx=i;
        }
        sort(a+1,a+n+1,cmpa);
        for(int i=1;i<=n;i++) a[i].acnt=i;
        sort(a+1,a+n+1,cmpb);
        for(int i=1;i<=n;i++) a[i].bcnt=i;
        sort(a+1,a+n+1,cmpc);
        for(int i=1;i<=n;i++) a[i].ccnt=i;
        for(int i=1;i<=n;i++){
            if(a[i].ccnt<a[i].bcnt&&a[i].ccnt<a[i].acnt&&cn+1<=n/2){
                sum+=a[i].c;
                cn++;
            }
            else if(a[i].acnt<a[i].bcnt&&a[i].acnt<a[i].ccnt&&an+1<=n/2){
                sum+=a[i].a;
                an++;
            }
            else if(a[i].bcnt<a[i].acnt&&a[i].bcnt<a[i].ccnt&&bn+1<=n/2){
                sum+=a[i].b;
                bn++;
            }
            else{
                ::t[++cnt]=a[i];
            }
        }
        for(int j=1;j<=cnt;j++){
            if(::t[i].a==::t[i].b&&::t[i].b==::t[i].c){
                int tt=min(an,min(bn,cn));
                if(tt==an){
                    an++;
                    sum+=::t[i].a;
                }
                else if(tt==bn){
                    bn++;
                    sum+=::t[i].b;
                }
                else{
                    cn++;
                    sum+=::t[i].c;
                }
            }
            else if(::t[i].a==::t[i].b){
                int tt=min(an,bn);
                if(tt==an){
                    an++;
                    sum+=::t[i].a;
                }
                else{
                    bn++;
                    sum+=::t[i].b;
                }
            }
            else if(::t[i].b==::t[i].c){
                int tt=min(bn,cn);
                if(tt==bn){
                    bn++;
                    sum+=::t[i].b;
                }
                else{
                    cn++;
                    sum+=::t[i].c;
                }
            }
            else{
                int tt=min(an,cn);
                if(tt==an){
                    an++;
                    sum+=::t[i].a;
                }
                else{
                    cn++;
                    sum+=::t[i].c;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
