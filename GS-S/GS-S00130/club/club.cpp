#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t>>n;
    int cnt=0;
        for(int i=1;i<=n;i++){
               int a=max(a,n);
                     cnt+=a;
        }
    cout<<cnt+2<<endl;
    //fclose(stdin);
    //fclose(stdout);
     return 0;
}
