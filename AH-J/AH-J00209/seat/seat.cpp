#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int as=a[1];
    sort(a+1,a+1+n*m,cmp);
    int i=1,j=1;
    bool f=0;
    for(int k=1;k<=n*m;k++){
        if(a[k]==as){
            cout<<j<<' '<<i;
            break;
        }
        if(i==n&&f==0){
            f=1;
            j++;
        }else if(i==1&&f==1){
            f=0;
            j++;
        }else{
            if(f==0){
                i++;
            }else{
                i--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
