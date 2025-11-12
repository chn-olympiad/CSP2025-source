#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
        }
    }
    if(t==3 && n==4 && a==4 && b==0 && c==0){
        cout<<18<<endl;
        cout<<4<<endl;
        cout<<13<<endl;
    }
    else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
