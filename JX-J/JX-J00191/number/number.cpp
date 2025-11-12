#include<bits/stdc++.h>
using namespace std;
char a[10000];
int x,n,m;
int main(){
//    freopen("number.in","r",stdin);
//    freopen("number.out","w",stdout);
    cin>>a;
    n=strlen(a);
    if(n==1){
        cout<<a;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='0'||a[i]=='9'||a[i]=='8'||a[i]=='7'||a[i]=='6'||a[i]=='5'||a[i]=='4'||a[i]=='1'||a[i]=='2'||a[i]=='3'){
            m++;
        }
        else{
            for(int j=i;j<=n;j++){
                a[j]=a[j+1];
            }
        }
    }


    for(int i=m;i>=0;i--){
        cout<<a[i];
    }

    return 0;
}
