#include<bits/stdc++.h>
using namespace std;
struct xs{
    int fs,p;
}s[105];
int c[13][13];
bool cmp(xs a,xs b){
    return a.fs>b.fs;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++){
        cin>>s[i].fs;
        s[i].p=i;
    }
    sort(s+1,s+1+x,cmp);
    int a1=1,a2=1;
    for(int i=1;i<=x;i++){
        c[a1][a2]=s[i].fs;
        if(s[i].p==1){
            cout<<a1<<" "<<a2;
            break;
        }
        if(a1%2==1){
            if(a2==n){
                a1++;
                continue;
            }
            a2++;
        }else{
            if(a2==1){
                a1++;
                continue;
            }
            a2--;
        }
    }
    return 0;
}
