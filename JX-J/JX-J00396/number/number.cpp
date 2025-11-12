#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int c=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;a[i]>1;i++){
        if((int)a[i]>=48&&(int)a[i]<=57){
            b[c]=a[i];
            c++;
        }
    }
    for(int i=1;i<c;i++){
        for(int j=c;j>i;j--){
            if(b[j]>b[j-1]){
                b[0]=b[j];
                b[j]=b[j-1];
                b[j-1]=b[0];
            }
        }
    }
    for(int i=1;i<=c;i++)
        cout<<b[i];
    return 0;
}
