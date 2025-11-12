#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("seat.in", "r", stdin);
freopen("seat.out", "w", stdout);
int n,m;
cin >> n >> m;
for(int i=1; i<=n*m; i++){
cin >> a[i];
}
int r=a[1];
int num;
sort(a+1, a+n+1,cmp);
for(int i=1; i<=n*m; i++){
    if(a[i]==r){
        num=i;
        break;
    }
}
int sum=n+1;
if(num<=n) cout << 1 << ' ' << num;
else if(num>n){
        for(int i=n; i>num%n; i--){
            sum--;
        }
    cout << num/n+1 << ' ' << sum;
}
return 0;
}
