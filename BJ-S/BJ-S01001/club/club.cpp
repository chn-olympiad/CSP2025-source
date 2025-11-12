#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10010;
int a[N],b[N],c[N];
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int t,n,cnt;
    cin >> t;
    while(t--){
        cnt=0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        sort(a+1,a+n+1);
        for(int i = n;i > n/2; i--){
                cnt+=a[i];
        }
        cout << cnt << endl;
    }
    return 0;
}
