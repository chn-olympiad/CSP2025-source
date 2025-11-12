// 注意：样例5.6未通过(upd:done)
// expect 70
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace hcx_sol1{
    // dp O(n mx)
    // un-array
    int a[440000];
    int f[4400][110000];
	void main(){
		int n,k;
        cin>>n>>k;
        int mx=k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        for(int i=1;i<=n;i++){
            f[i][0]=f[i-1][0];
            for(int j=0;j<=mx;j++){
                if(j==k){
                    f[i][0]=max(f[i][0],f[i-1][j^a[i]]+1);
                }else{
                    f[i][0]=max(f[i][0],f[i-1][j^a[i]]);
                    f[i][j]=max(f[i][j],f[i-1][j^a[i]]);
                }
            }
        }
        int ans=0;
        for(int j=0;j<=mx;j++){
            ans=max(f[n][j],ans);
            //cout<<f[n][j]<<" ";
        }
        cout<<ans<<"\n";
	}
}
namespace hcx_sol2{
    // dp O(n mx)
    // un-array
    int a[440000];
    int f[2][2100000];
	void main(){
		int n,k;
        cin>>n>>k;
        int tmx=k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            tmx=max(tmx,a[i]);
        }
        int mx=1;
        for(;mx-1<tmx;mx<<=1);
        //cerr<<mx<<"\n";
        int nw=1,tw=0;
        for(int i=0;i<=mx;i++)f[tw][i]=-0x3f3f3f3f;
        f[tw][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=mx;j++)f[nw][j]=-0x3f3f3f3f;
            f[nw][0]=f[tw][0];
            for(int j=0;j<=mx;j++){
                if(j==k){
                    f[nw][0]=max(f[nw][0],f[tw][j^a[i]]+1);
                }else{
                    f[nw][0]=max(f[nw][0],f[tw][j^a[i]]);
                    f[nw][j]=max(f[nw][j],f[tw][j^a[i]]);
                }
            }
            swap(nw,tw);
        }
        int ans=0;
        for(int j=0;j<=mx;j++){
            ans=max(f[tw][j],ans);
            //cout<<f[tw][j]<<" ";
        }
        cout<<ans<<"\n";
	}
}
namespace hcx_sol3{
    int a[33];
    void main(){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int m=1<<n;
        int ans=0;
        for(int i=1;i<m;i++){
            int la=0,ji=0;
            int res=0;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    if(la==j-1){
                        ji^=a[i];
                    }else{
                        res+=ji==k;
                        ji=a[i];
                    }
                    la=j;
                }
            }
            res+=ji==k;
            ans=max(ans,res);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //hcx_sol1::main();
	hcx_sol2::main();
    //hcx_sol3::main();
	return 0;
}