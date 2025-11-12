#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a=0,n=0,m=0,g=0,s=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s;
        if(i==0) g=s;
        else{
            if(s>g) a+=1;
        }
    }
    if(a/n%2==0) cout<<a/n+1<<' '<<a%n+1;
    if(a/n%2==1) cout<<a/n+1<<' '<<n-a%n;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
