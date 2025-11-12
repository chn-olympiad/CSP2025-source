#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("club.out");
ifstream fin("club.in");
const int N = 1e5+10;

int T,n,mxN,ans;
int a[N][3],b[N][3],cnt[3][3];
int d[3];

int max3(int a,int b,int c){
    return max(max(a,b),c);
}
int main(){
    fout.sync_with_stdio(false);
    fin.sync_with_stdio(false);
    fout.tie(nullptr);
    fin.tie(nullptr);

    fin>>T;
    while(T--){
        ans=0;
        d[0]=d[1]=d[2]=0;
        fin>>n;
        mxN = n/2;
        for(int i=1;i<=n;i++){
            fin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
                b[i][0]=0,b[i][1]=(a[i][1]>a[i][2]?1:2),b[i][2]=(a[i][1]<a[i][2]?1:2);
            else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2])
                b[i][0]=1,b[i][1]=(a[i][0]>a[i][2]?0:2),b[i][2]=(a[i][0]<a[i][2]?0:2);
            else
                b[i][0]=2,b[i][1]=(a[i][0]>a[i][1]?0:1),b[i][2]=(a[i][0]<a[i][1]?0:1);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                if(d[b[i][j]]<mxN){
                    d[b[i][j]]++;
                    ans += a[i][b[i][j]];
                    break;
                }
            }
        }
        fout<<ans<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
