#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],a1;
int f[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int z=n*m;
    for(int i=1;i<=z;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+z+1,cmp);
    int pos;
    for(int i=1;i<=z;i++){
        if(a[i]==a1){
            pos=i;
            break;
        }
    }
    int posl=pos/n;
    if(pos%n>0){
        posl++;
    }
    int posh;
    if(posl%2==1){
        posh=pos%n;
        if(pos%n==0){
            posh=n;
        }
    }else{
        posh=n-pos%n+1;
        if(pos%n==0){
            posh=1;
        }
    }
    cout<<posl<<" "<<posh;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
