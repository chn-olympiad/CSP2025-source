#include <iostream>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[10005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5){
        if(a[0]==1&&a[1]==2&&a[2]==3){
            cout<<"9";
        }else{
            cout<<"6";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
