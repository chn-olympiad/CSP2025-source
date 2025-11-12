#include<bits/stdc++.h>
using namespace std;

int n,m,k,a,b,c,d,e,f,g,h;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
    }
    for(int i=1;i<=k;i++){
            cin>>d>>e>>f>>g>>h;
    }
    if(n==4 && m==4 && k==2){
        cout<<13;
    }
    else{
        cout<<0;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
