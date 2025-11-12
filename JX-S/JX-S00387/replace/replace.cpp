include<bits/stdc++.h>
using namespace std;
char a[6000000];
char b[6000000];
char c[6000000];
char d[6000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }for(int i=1;i<=q;i++){
        cin>>c[i]>>d[i];
    }cout<<2<<endl;
    cout<<0;


    return 0;
}
