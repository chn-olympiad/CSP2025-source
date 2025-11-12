#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[11][11];
bool cmp(int x,int y){
    return x > y;
}int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num,r,c;
    cin>>n>>m;
    int tmp = n * m;
    for(int i = 1;i <= tmp;i++){
        cin>>a[i];
    }num = a[1];
    sort(a,a + tmp + 1,cmp);
    int ind = 0;
    for(int i = 1;i <= m;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= n;j++){
                if(a[ind++] == num){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }else{
            for(int j = n;j >= 1;j--){
                if(a[ind++] == num){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }return 0;
}
