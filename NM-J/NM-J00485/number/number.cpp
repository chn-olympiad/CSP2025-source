#include <iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char in,a[1000005];
    int b[1000005];
    for(int i=0;i<1000005;i++){
        cin>>a[i];
    }
    int j=0;
    for(int i=0;i<1000005;i++){
        if(a[i]>='0' && a[i]<='9'){
            b[j]=a[i]-'0';
            j++;
        }
    }
    for(int k=0;k<=j;k++){
        for(int l=k;l<j;l++){
            if(b[l]<b[l+1]){
                int c=0;
                c=b[l];
                b[l]=b[l+1];
                b[l+1]=c;
            }
        }
    }
    for(int k=1;k<=j;k++){
        cout<<b[k];
    }
}
