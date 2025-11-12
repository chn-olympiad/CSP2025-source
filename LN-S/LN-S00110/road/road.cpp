#include<bits/stdc++.h>
using namespace std;
long long n,m,d,e,a,b,c,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            sum=sum+c;
    }
    for(int i=0;i<d;i++){
        cin>>e;
    }
    cout<<sum<<endl;
    return 0;
}
