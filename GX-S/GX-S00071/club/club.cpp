#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("//home//noilinux//club//club.in","r",stdin);
    freopen("//home//noilinux//club//club.out","w",stdout);
    cin>>n;//表示测试数据组数
    for(int u=1;u<=n;u++){
        int sum=0;
        cin>>m;//表示新成员的数量
        int xsum,ysum,zsum,xres,yres,zres;
        for(int i=1;i<=m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(max(x,y)==x&&max(x,z)==x){
                    sum+=x;
                    xres++;
            }
            if(max(x,y)==y&&max(y,z)==y){
                    sum+=y;
            }
            if(max(z,y)==z&&max(x,z)==z){
                    sum+=z;
                    zres++;
            }
            //cout<<sum<<endl;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
