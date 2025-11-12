#include<bits/stdc++.h>
using namespace std;
struct j{
    int a,b,c;
};
j club[100001];
bool cmp1(j a,j b){
    return a.a>b.a;
}
bool cmp2(j a,j b){
    return a.b>b.b;
}
bool cmp3(j a,j b){
    return a.c>b.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long n,ma=-1,p=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>club[i].a>>club[i].b>>club[i].c;
        }
        int m=n/2;
        sort(club+1,club+1+n,cmp1);
        p=0;
        for(int i=1;i<=n/2;i++){
            p+=club[i].a;
        }
        for(int i=n/2+1;i<=n;i++){
            p+=max(club[i].b,club[i].c);
        }
        if(p>ma){
            ma=p;
        }

        sort(club+1,club+1+n,cmp2);
        p=0;
        for(int i=1;i<=n/2;i++){
            p+=club[i].b;
        }
        for(int i=n/2+1;i<=n;i++){
            p+=max(club[i].a,club[i].c);
        }
        if(p>ma){
            ma=p;
        }

        sort(club+1,club+1+n,cmp3);
        p=0;
        for(int i=1;i<=n/2;i++){
            p+=club[i].c;
        }
        for(int i=n/2+1;i<=n;i++){
            p+=max(club[i].a,club[i].b);
        }
        if(p>ma){
            ma=p;
        }
        cout<<ma<<endl;
    }
    return 0;
}
