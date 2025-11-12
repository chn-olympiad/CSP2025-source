#include<iostream>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int grade=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[i]>a[j]){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
            else{
                continue;
            }
        }

    }
    int index;
    for(int i=1;i<=n*m;i++){
        if(a[i]==grade){
            index=i;
            break;
        }
    }
    int c=1,r=0;
    for(int i=1;i<=index;i++){
        if(r<n&&c%2==1){
            r++;
        }
        else if(c%2==0&&r>1){
            r--;
        }
        else if((r==n&&c%2==1)||(r==1&&c%2==0)){
            c++;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
