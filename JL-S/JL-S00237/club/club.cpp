#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005],c[100005];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    //freopen("club1.in","r",stdin);
    //freopen("club1.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i] >> b[i]>> c[i];
        }
        if(n == 2){
            return 0;
        }
        sort(a+1,a+n+1,cmp);
        int sum = 0;
        for(int i = 1;i <= n / 2;i++){
            sum += a[i];
        }
        cout <<sum <<endl;
    }

    return 0;
}
