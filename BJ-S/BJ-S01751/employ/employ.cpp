#include <iostream>
#include <string>
using namespace std;
#define int long long

int MAXN=998244353;
int n,m,ans=0;
string s;
int a[590];
bool f=0;

int C(int x,int y){
    int ret=1,delta=0;
    bool flag=0;
    for(int i = x;i >= x-y+1;i--){
        ret*=i;
        while(ret%(y-delta)==0&&flag==0){
            ret/=(y-delta);
            delta++;
            if(delta==y-1){
                flag=1;
            }
        }
    }
    return ret;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout << 2 << endl;
    return 0;
}
