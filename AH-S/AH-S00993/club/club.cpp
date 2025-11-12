#include<bits/stdc++.h>
using namespace std;
struct note{
    int a,b,c,d,e;
}a[100005];
int da(note s){return max(max(s.a,s.b),s.c);}//zuida
int zo(note s){return s.a+s.b+s.c-max(max(s.a,s.b),s.c)-min(min(s.a,s.b),s.c);}//zhongjian
int xi(note s){return min(min(s.a,s.b),s.c);}//zuixiao
int e(note s){
    if(s.a==da(s))return 0;
    if(s.b==da(s))return 1;
    if(s.c==da(s))return 2;
}
int d(note s){
    if(s.a==zo(s))return 0;
    if(s.b==zo(s))return 1;
    if(s.c==zo(s))return 2;
}
bool cmp(note x,note y){
    return da(x)-zo(x)>da(y)-zo(y);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,m=0;
        int k[3]={0};
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].d=d(a[i]);
            a[i].e=e(a[i]);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            if(k[a[i].d]<n/2){
                k[a[i].d]++;
                m+=da(a[i]);
            }
            else if(k[a[i].e]<n/2){
                k[a[i].e]++;
                m+=zo(a[i]);
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
