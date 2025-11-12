#include<bits/stdc++.h>
using namespace std;
struct stu{
    int x;
    int r;
    int t;
};
stu a[1100];
stu b[1100];
stu c[1100];
bool cmp(stu a,stu b){
    return a.x>b.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int m,n;
    cin>>m;
    for(int h=1;h<=m;h++){
        cin>>n;
        //cout<<n<<endl;
        int sum=0;
        for(int i=1;i<=n;i++){
            a[i].x=0;
            b[i].x=0;
            c[i].x=0;
            a[i].t=0;
            b[i].t=0;
            c[i].t=0;
            a[i].r=0;
            b[i].r=0;
            c[i].r=0;
        }
        //cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>b[i].x>>c[i].x;
            a[i].r=i;
            b[i].r=i;
            c[i].r=i;
            if(a[i].x>b[i].x&&a[i].x>c[i].x){
                a[i].t=1;
                /*if(b[i].x>c[i].x){
                    b[i].t=2;
                    c[i].t=3
                }else{
                    b[i].t=3;
                    c[i].t=2;
                }*/
            }
            if(b[i].x>=a[i].x&&b[i].x>=c[i].x){
                b[i].t=1;
                /*f(b[i].x>c[i].x){
                    b[i].t=2;
                    c[i].t=3
                }else{
                    b[i].t=3;
                    c[i].t=2;
                }*/
            }
            if(c[i].x>=b[i].x&&c[i].x>=a[i].x){
                c[i].t=1;
                /*f(b[i].x>=c[i].x){
                    b[i].t=2;
                    c[i].t=3
                }else{
                    b[i].t=3;
                    c[i].t=2;
                }*/
            }
        }
        //cout<<n<<endl;
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        //cout<<n<<endl;
        /*for(int i=1;i<=n;i++){
            cout<<a[i].x<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<b[i].x<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<c[i].x;
        }*/
        int sx=n/2;
        int k=1;
        //cout<<n<<endl;
        while(n!=0){
            if(a[1].t==1){
                a[1].t=0;
                sum+=a[1].x;
                a[1].x=0;
                n--;
                sort(a+1,a+n+1,cmp);
            }
            if(b[1].t==1){
                b[1].t=0;
                sum+=b[1].x;
                b[1].x=0;
                n--;
                sort(b+1,b+n+1,cmp);
            }
            if(c[1].t==1){
                c[1].t=0;
                sum+=c[1].x;
                c[1].x=0;
                n--;
                sort(c+1,c+n+1,cmp);
            }

        }
        //cout<<n<<endl;
        cout<<sum<<endl;
        //cout<<1;
    }

    return 0;
}
