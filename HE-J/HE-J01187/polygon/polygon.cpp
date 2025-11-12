#include <iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}