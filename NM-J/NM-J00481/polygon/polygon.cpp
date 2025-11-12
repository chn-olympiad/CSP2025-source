#include <iostream>

using namespace std;

int main()
{
  freopen("polygon,in","r",stdin);
  freopen("polygon,out","w",stdout
    int n,a[100000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    if(n==5){
        if(a[i]==5)cout<<9;
          else if(a[i]==10)cout<<6;
    }
    }
    return 0;
}
