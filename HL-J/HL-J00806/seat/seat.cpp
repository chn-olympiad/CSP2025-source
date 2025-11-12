#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace hcx{
    int a[110];
    int b[22][22];
    bool cmp(int x,int y){
        return x>y;
    }
	void main(){
		int n,m;
        cin>>n>>m;
        int k=n*m;
        for(int i=1;i<=k;i++){
            cin>>a[i];
        }
        int key=a[1];
        sort(a+1,a+k+1,cmp);
        int idx=0;
        for(int j=1;j<=m;j++){
            int ste,sta;
            if(j&1)ste=+1,sta=1;
            else ste=-1,sta=n;
            for(int i=sta;i<=n&&i>=1;i+=ste){
                b[i][j]=a[++idx];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==key){
                    cout<<j<<" "<<i<<"\n";
                    return;
                }
            }
        }
	}
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	hcx::main();
	return 0;
}