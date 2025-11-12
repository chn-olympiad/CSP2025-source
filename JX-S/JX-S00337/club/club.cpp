#include<bits/stdc++.h>
using namespace std;
int c[4]={},b[10005];
int head=0,tail=0,k=1,j=1;
int main(){
    //freopen("club2.in","r",stdin);
    //freopen("club2.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int  a[n+1][4];
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            head+=a[i][1];
        }
        cout<<head;
    }
    return 0;
}
