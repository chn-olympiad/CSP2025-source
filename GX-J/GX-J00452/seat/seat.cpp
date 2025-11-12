#include <iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m],b[m][n];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<m;j++){
            cin>>a[i];
        }
    }
    int a1=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    bool b=ture;
    for(int i=0;i<m;i++){
        if(b==turn){
            for(int j=0;j<n;j++){
                b[i][j]=a[x];
                x++;
            }
            b=false;
        }
        if(b==false{
            for(int j=n-1;j>0;j--){
                b[i][j]=a[x];
                x++;
            }
            b=ture;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]==a1){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}