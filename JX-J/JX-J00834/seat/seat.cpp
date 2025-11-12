#include<bits/stdc++.h>
using namespace std;
const int N=15*15;
int a[N],sum;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    sum=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sum){
            int x=1,y=1;
            for(int j=1;j<i;j++){
                if(x%2==1){
                    if(y<n){
                        y++;
                    }
                    else{
                        x++;
                    }
                }else{
                    if(y>1){
                        y--;
                    }else{
                        x++;
                    }
                }
            }
            cout<<x<<" "<<y;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
