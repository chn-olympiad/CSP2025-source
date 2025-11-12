#include<bits/stdc++.h>
using namespace std;
//wu ri n xing wu shen:
//define int long long & signed main hu?
//freopen shan zhu shi hu?
//da yang li ce shi le hu?
//bian liang chu shi hua le hu?
//han shu xie fan hui zhi le hu?
//shu zu da xiao he shi hu?
//bu yong zi mu+shu zi / wan zheng dan ci zuo bian liang ming hu?
//bian yi tong guo le hu?
//jian cha shu chu shi kong ge hai shi huan hang le hu?
//heng zong zuo biao wei zhi zheng que hu?
#define int long long
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+2];
    for(int i=0;i<n*m;i++)cin>>a[i];
    int t=a[0];
    sort(a,a+n*m);
    reverse(a,a+n*m);
    int ni=0,nj=0,flag=1,cnt=0;
    int ans[n+2][m+2];
    while(ni<n&&nj<m){
        ans[ni][nj]=a[cnt];
        if(a[cnt]==t){
            cout<<nj+1<<" "<<ni+1;
            return 0;
        }
        if(ni==n-1 && nj%2==0)nj++,flag*=-1;
        else{
            if(ni==0 && nj%2==1)nj++,flag*=-1;
            else ni+=flag;
        }
        cnt++;
        if(cnt==n*m)break;
    }
    return 0;
}
