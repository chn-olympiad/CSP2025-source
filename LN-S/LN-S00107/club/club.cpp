#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
    freopen("culb.in","r",stdin);
    freopen("culb.out","w",stdout);
    int t,n,i,j,m=0;
    cin>>t;
    int s[t+1];
    for(int b=1;b<=t;b++){
        s[b]=0;
        cin>>n;
        for(i=1;i<=n;i++){
            m=0;
            for(j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>m)
                    m=a[i][j];
            }
            s[b]+=m;
        }
    }
    for(int b=1;b<=t;b++)
        cout<<s[b]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
