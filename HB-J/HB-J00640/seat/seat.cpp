#include <iostream>
#include <algorithm>
using namespace std;
int n,m,sc[101],xr,posxr,curr;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> sc[i];
        if(i==1) xr=sc[i];
    }
    sort(sc+1,sc+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) if(sc[i]==xr){ posxr=i; break; } //找到小R是第几名
    for(int i=1;i<=n;i++)       //列
        if(i%2){    //考虑列数为奇数的情况（向下分配）
            for(int j=1;j<=m;j++){  //行
                if(++curr==posxr){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }else{      //考虑列数为偶数的情况（向上分配）
            for(int j=m;j>=1;j--){  //行
                if(++curr==posxr){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    return 0;
}