#include <iostream>

using namespace std;

int main()
{
    int n=0,m=0;
    cin>>n>>m;
    int b[(n*m)+1];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int h=b[1];
    for(int i=1;i<n*m;i++){
        for(int j=1;j<n*m;j++){
            if(b[j]<b[j+1])
                swap(b[j],b[j+1]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(h==b[j]){
                cout<<i<<" "<<j;
                break;
            }

        }
    }
    return 0;
}
