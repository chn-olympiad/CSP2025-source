#include<iostream>
#include<cstdio>
using namespace std;
int m,n,k;
int sum;
string s,z;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int l=1,a,b,c;l<=m;l++){
        cin>>a>>b>>c;
        sum+=c;
    }
    for(int l=1;l<=k;l++){
        for(int i=1,a;i<=n+1;i++){
            cin>>a;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
