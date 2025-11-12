#include <bits/stdc++.h>
using namespace std;
int t,n;
int solve(int n){
int a[100005][8],b[100005],c[100005],tot;
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
        for(int i=0;i<n;i++){
            b[i]=a[i][1];
        }
        for(int i=0;i<n;i++){
            c[i]=a[i][2];
        }
        sort(b,b+n);
        sort(c,c+n);
        for(int i=n;i>=n/2;i--){

            tot+=max(b[i],c[i]);

        }
        cout<<tot;
        tot=0;
}

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
        cin>>n;
    solve(n);
}

return 0;
fclose(stdin);
fclose(stdout);
}
