#include<bits/stdc++.h>
using namespace std;
int t,n;
struct stu
{
    int c=0,b=0;
}a[100002];
bool cmp1(stu x1,stu y1)
{
    if(x1.b!=y1.b){
        return x1.b<y1.b;
    }
    return x1.c<y1.c;
}
bool cmp2(stu x2,stu y2)
{
    if(x2.b+y2.b==3) return x2.b>y2.b;
    if(x2.b+y2.b==5) return x2.b<y2.b;
    return x2.c<y2.c;
}
bool cmp3(stu x3,stu y3)
{
    if(x3.b!=y3.b) return x3.b>y3.b;
    return x3.c<y3.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int x,y,z,c1=0,c2=0,c3=0,m=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(z>=x&&z>=y){
                m+=z;
                a[i].b=3;
                c3++;
                a[i].c=min(z-x,z-y);
            }
            else if(y>=x&&y>=z){
                m+=y;
                a[i].b=2;
                c2++;
                a[i].c=min(y-x,y-z);
            }
            else {
                m+=x;
                a[i].b=1;
                c1++;
                a[i].c=min(x-z,x-y);
            }
 //           cout<<i<<" "<<a[i].b<<" "<<a[i].c<<endl;

        }
        int n1=n/2;
        if(c1<=n1&&c2<=n1&&c3<=n1){
            cout<<m<<endl;
            continue;
        }
        if(c1>n1){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=c1-n1;i++){
                m-=a[i].c;
            }
            cout<<m<<endl;
            continue;
        }
        if(c2>n1){
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=c2-n1;i++){
                m-=a[i].c;
            }
            cout<<m<<endl;
            continue;
        }
        if(c3>n1){
            sort(a+1,a+n+1,cmp3);
            for(int i=1;i<=c3-n1;i++){
                m-=a[i].c;
            }
            cout<<m<<endl;
            continue;
        }
    }
    return 0;
}
