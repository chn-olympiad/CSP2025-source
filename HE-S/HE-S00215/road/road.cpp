#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;//城市数量、道路数量和准备进行城市化改造的乡镇数量.
    cin>>m;
    cin>>n>>k;
    int a[m][3];
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>a[i];
        }
    }
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
