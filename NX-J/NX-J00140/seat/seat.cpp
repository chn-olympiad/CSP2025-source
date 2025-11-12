#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int x;
    int s1,s2,t;
    for(int i = 1;i <= n*m;i++)cin >> a[i];
    x = a[1];
    int k = 1;
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(i%2==0){
                t = n-j+1;
            }else{
                t = j;
            }
            if(a[k] == x){
                cout << i << " " << t;
                return 0;
            }
            k++;
        }
    }

    return 0;
}
