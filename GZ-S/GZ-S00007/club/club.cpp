//GZ-S00007 安顺市平坝区实验小学 付新峻羽
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,ma,maxx=0,maxx1=0;
int s[3];
struct cl{
    int a;
    int b;
    int c;
}a[100005];
bool cmp(cl c,cl d){
    if(c.a>d.a) return true;
    else if(c.a==d.a && c.b>d.b)    return true;
    else if(c.a==d.a && c.b==d.b && c.c>d.c)    return true;
    else return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        cin>>m;
        for(int i = 0;i<m;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a,a+m,cmp);
            int m1=max(a[0].a,a[0].b);
            int m2=max(a[0].c,m1);
            int m3=max(a[1].a,a[1].b);
            int m4=max(a[1].c,m3);
            if((m2==a[0].a && m4 == a[1].a)){
               int m5=max(a[0].b,a[0].c);
               maxx1=m4+m5;
            }else if((m2==a[0].b && m4 == a[1].b)){
                int m5=max(a[0].a,a[0].c);
                maxx1=m4+m5;
            }else if((m2==a[0].c && m4==a[1].c)){
                maxx1=m1+m4;
            }
            for(int i = 0 ;i<m ;i++){
	            if(s[0]>m/2){
	                a[i].a=0;
	            }else if(s[1]>m/2){
	                a[i].b=0;
	            }else if(s[2]>m/2){
	                a[i].c=0;
	            }
	            if(a[i].a>a[i].b && a[i].a>a[i].c && s[0]<=m/2){
	                ma=0;
	                maxx=a[i].a;
	            }else if(a[i].b>a[i].a && a[i].b>a[i].c && s[1]<=m/2){
	                ma=1;
	                maxx=a[i].b;
	            }else if(a[i].c>a[i].b && a[i].c>a[i].a && s[2]<=m/2){
	                ma=2;
	                maxx=a[i].c;
	            }
	            s[ma]++;
	            cnt+=maxx;
	            maxx=0;
        }
            cout<<max(cnt,maxx1)<<"\n";
            cnt=0;
    }
    return 0;
}
