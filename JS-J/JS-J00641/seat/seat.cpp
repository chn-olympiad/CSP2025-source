#include<bits/stdc++.h>
using namespace std;
int m[115115];
bool cmp(int a,int b){
    if(a>b)return true;
    return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,s,l=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            cin>>m[++l];
        }
    }
    int flag=m[1],xb=1;
    sort(m+1,m+l+1,cmp);
    for(;m[xb]!=flag;xb++);
    cout<<(xb+n-1)/n<<" ";
    if(((xb+n-1)/n)%n==1)cout<<xb%n;
    else cout<<s-(xb-1)%n;
    return 0;
}
