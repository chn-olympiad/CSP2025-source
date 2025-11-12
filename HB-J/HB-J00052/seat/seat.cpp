#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s1;
    int a[107]={0};
    int s[15][15];
    cin>>n>>m>>s1;
    a[1]=s1;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+(n*m),cmp);
    int t=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;i<=n;j++){
                if(a[++t]==s1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[++t]==s1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
