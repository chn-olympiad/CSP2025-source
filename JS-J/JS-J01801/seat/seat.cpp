#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int size;
int x;
int i=1,j=1;
int dir=1;//1 XIA,2 SHANG,3 YOU
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    size=n*m;
    x=a[1];
    sort(a+1,a+size+1,greater<int>());
    for(int k=1;k<=size;k++){
        if(a[k]==x) cout<<j<<" "<<i<<endl;
        if(i+1>n) {
           if(dir==1) {
                dir=3;
                j++;
           }
           else if(dir==3){
                dir=2;
                i--;
           }
           else i--;
        }
        else if(i-1<=0){
            if(dir==2){
                dir=3;
                j++;
            }
            else if(dir==3){
                dir=1;
                i++;
            }
            else i++;
        }
        else if(dir==1){
            i++;
        }
        else if(dir==2){
            i--;
        }
    }
    return 0;
}
