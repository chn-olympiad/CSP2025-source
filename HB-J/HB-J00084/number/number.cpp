#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number","r",stdin);
    //freopen("number","w",stdout);
    char s;
    cin>>s;
    int a[1000];
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            if(a[j]<a[j+1]){
                int b=a[j+1];
                a[j+1]=a[j];
                a[j]=b;
            }
        }
    }
    cout<<s;


    return 0;
}
