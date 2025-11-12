#include<bits/stdc++.h>
using namespace std;
struct S{
    int number;
    int b;
}s[105];
bool cmp(S a1,S a2){
    return a1.number>a2.number;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[15][15];
    cin >>n>>m;
    int ans=0;
    for(int i=1;i<=n*m;i++){
        cin >>s[i].number;
        s[i].b=i;
        ans++;
    }
    int n1=1,m1=1;
    bool flag=true;
    int cnt=1;
    sort(s+1,s+n*m+1,cmp);
    while(1){
        if(flag){
            for(n1;n1<=n;){
                a[n1][m1]=s[cnt].b;
                if(a[n1][m1]==1){
                    cout<<m1<<" "<<n1<<endl;
//                    cout<<s[cnt].number;
                    return 0;
                }
                cnt++;
                n1++;
            }
            n1-=1;
            m1++;
            flag=false;
        }else{
            for(n1;n1>=1;){
                a[n1][m1]=s[cnt].b;
                if(a[n1][m1]==1){
                    cout<<m1<<" "<<n1<<endl;
//                    cout<<s[cnt].number;
                    return 0;
                }
                cnt++;
                n1--;
            }
            n1+=1;
            m1++;
            flag=true;
        }
    }
    return 0;
}