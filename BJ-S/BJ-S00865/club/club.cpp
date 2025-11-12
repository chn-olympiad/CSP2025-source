#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
struct student
{
    int a,b,c;
    student(int a=0,int b=0,int c=0):a(a),b(b),c(c) {}
}a[Maxn];
int n,ans,now;
int cnt_a,cnt_b,cnt_c;
bool cmp_a(student x,student y)
{
    return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);
}
bool cmp_b(student x,student y)
{
    return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);
}
bool cmp_c(student x,student y)
{
    return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);
}
void run()
{
    cin>>n; ans=cnt_a=cnt_b=cnt_c=0;
    for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
    int lst=n,i;
    sort(a+1,a+lst+1,cmp_a);
    for(i=lst;i>=lst-(n>>1)+1;i--)
    {
        if(a[i].a-max(a[i].b,a[i].c)<0) break;
        ans+=a[i].a; cnt_a++;
    }
    lst=i;
    sort(a+1,a+lst+1,cmp_b);
    // cout<<lst<<" "<<ans<<endl;
    // for(int j=1;j<=lst;j++) cout<<a[j].a<<" "<<a[j].b<<" "<<a[j].c<<endl;
    for(i=lst;i>=max(1,lst-(n>>1)+1);i--)
    {
        if(a[i].b-max(a[i].a,a[i].c)<0) break;
        ans+=a[i].b; cnt_b++;
    }
    lst=i;
    sort(a+1,a+lst+1,cmp_c);
    // cout<<lst<<" "<<ans<<endl;
    // for(int j=1;j<=lst;j++) cout<<a[j].a<<" "<<a[j].b<<" "<<a[j].c<<endl;
    for(i=lst;i>=max(1,lst-(n>>1)+1);i--)
    {
        if(a[i].c-max(a[i].a,a[i].b)<0) break;
        ans+=a[i].c; cnt_c++;
    }
    lst=i;
    // cout<<lst<<" "<<ans<<endl;
    // for(int j=1;j<=lst;j++) cout<<a[j].a<<" "<<a[j].b<<" "<<a[j].c<<endl;
    for(i=lst;i>=1;i--)
    {
        int na=a[i].a*(cnt_a<(n>>1));
        int nb=a[i].b*(cnt_b<(n>>1));
        int nc=a[i].c*(cnt_c<(n>>1));
        if(na>nb && na>nc) ans+=a[i].a,cnt_a++;
        else if(nb>na && nb>nc) ans+=a[i].b,cnt_b++;
        else ans+=a[i].c,cnt_c++;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) run();
    return 0;
}
/*
19722+16615+16441+8769+16178+15344+18961+10557+9953+14615
*/