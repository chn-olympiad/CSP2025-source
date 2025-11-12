#include <bits/stdc++.h>
using namespace std;
bool cmd(const int& a, const int& b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n*m);
    for(int i = 0;i<n*m;i++){
        cin >> a[i];
    }
    int q = a[0];
    sort(a.begin(),a.end(),cmd);
    int num = 0;
    for(int i =0;i<n*m;i++){
        if(a[i]==q)break;
        num++;
    }

    int s = num/n+1;
    cout << s << " ";
    int y = num%n+1;
    if(s%2==0){
        cout << n+1-y;
    }else if(s%2==1){
        cout << y;
    }
    return 0;
}
