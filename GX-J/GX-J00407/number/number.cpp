#include<bits/stdc++.h>
using namespace std;
char a[1000006],b;
int j,m,c,x,i;
int sc(){
    for(j=0;j<=1000000;j++){
        cout<<a[j];
    }
    cout<<endl;
    return 0;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(x=0;x<=1000000;x++){
        if(int(a[x])>57||int(a[x])<48){
            a[x]=0;
        }
    }
    for(i=0;i<=1000000;++i){
        m=i;
        while(a[m]>a[m-1]&&m!=0){
            c=a[m];
            a[m]=a[m-1];
            a[m-1]=c;
            --m;
        }
    }
    sc();
    return 0;
}
