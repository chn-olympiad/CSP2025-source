#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a,b=1;
char c[100];
char r[100];
char f[100];
int e;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    while(k--){
        cin>>c[a];
        a++;
    }
    for(int i=0;i<100;i++){
        b=0;
        for(int j=0;j<99;j++){
            if(c[j]<c[b]){
                r[0]=c[j];
                c[j]=c[b];
                c[b]=r[0];
                if(e<=b){
                    e=b+1;
                }
                b++;
            }
            else{
                f[b]=c[b];
                b++;
            }
        }
    }
    cout<<e/n+1<<" ";
    if((e/n+1)%2==1)
        cout<<e/n+n;
    else
        cout<<"1";
    return 0;
}
