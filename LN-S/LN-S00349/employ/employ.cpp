#include<bits/stdc++.h>
using namespace std;
int s[100005],c[100005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int s[i],c[i];
    }
    int j,x=0;
    for(int i=1;i<=n;i++){
        if(s[i]%2==1){
            x++;
        }
        cin>>s[j];
        if(s[i]+c[i]-s[j]>=0){
            x--;
        }
    }
    int y=0;
    if(x>=m){
        y=x-m;
    }
    else{
        cout<<2<<endl;
    }
    cout<<y<<endl;
    return 0;
}
