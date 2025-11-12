#include <iostream>
using namespace std;
int main(){
    int n,m,x,xy,yy,z;
    cin>>n>>m;
    char s[n*m+1],c[1],xx[1];
    cin>>s[1];
    xx[0]=s[1];
    for(int i=2;i<=n*m-1;i++){
        cin>>s[i];
    }
    for(int i=0;i<n*m;i++){
        if(s[i]<s[i+1]){
            c[0]=s[i];
            s[i]=s[i+1];
            s[i+1]=c[0];
        }
    }
    for(int i=1;i<=n*m;i++){
        if(s[i]==xx[0]) x=i;
    }
    xy=x/4;yy=x%4;
    if(xy%2==0){
        cout<<yy;
    }else{
        cout<<4 - yy;
    }
    return 0;
}