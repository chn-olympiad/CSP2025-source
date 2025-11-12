#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p;
    cin>>n>>m;
    cin>>p;
    int c=p,sum=0;
    for(int i=2;i<=n*m;i++){
        cin>>p;
        if(p>c){
            sum++;
        }
    }
    int x,y;
    if((sum/n+1)%2==1){
        x=sum%n+1;
    }else{
        x=n-(sum%n);
    }
    y=sum/n+1;
    cout<<y<<' '<<x<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
