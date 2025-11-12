#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N],b[N],c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,sum = 0;
    cin >> n >> m >> k;
    for(int i = 1;i<=m;i++){
		cin >> a[i] >> b[i] >> c[i];
		sum+=a[i];
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
