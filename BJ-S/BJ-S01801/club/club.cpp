#include <bits/stdc++.h>

using namespace std;
struct student{
    int a,b,c;
}s[100005];
int b[100005][5];
bool cmpa(student a,student b){
    return a.a>b.a;
}
int eqs(int a,int b,int c,int d){
    int ans=0;
    if(a==b) ans++;
    if(a==c) ans++;
    if(a==d) ans++;
    if(b==c) ans++;
    if(b==d) ans++;
    if(c==d) ans++;
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        sort(s+1,s+n+1,cmpa);
        int cnt=0;
        if(n==2){
            cnt=max(cnt,s[1].a+s[2].b);
            cnt=max(cnt,s[1].a+s[2].c);
            cnt=max(cnt,s[1].b+s[2].a);
            cnt=max(cnt,s[1].b+s[2].c);
            cnt=max(cnt,s[1].c+s[2].a);
            cnt=max(cnt,s[1].c+s[2].b);
            cout<<cnt<<endl;
        }else if(n==4){
            for(int i=1;i<=n;i++){
                b[i][1]=s[i].a;
                b[i][2]=s[i].b;
                b[i][3]=s[i].c;
            }
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int l=1;l<=3;l++){
                            if(eqs(i,j,k,l)<=1) cnt=max(cnt,b[1][i]+b[2][j]+b[3][k]+b[4][l]);
                        }
                    }
                }
            }
            cout<<cnt<<endl;
        }
        else{
            for(int i=1;i<=n/2;i++){
                cnt+=s[i].a;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
