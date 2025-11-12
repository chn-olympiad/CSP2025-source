#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int N=15;
using namespace std;

int it,n,m,x,num;
vector<int> a;

bool cmp(int x,int y){return x>y;}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> it,a.push_back(it);
    rep(i,2,n*m) cin >> x,a.push_back(x);
    sort(a.begin(),a.end(),cmp);
    for(int x:a){
        num++;
        if(x==it) break;
    }
    if(num%n==0){
        cout << num/n << " " << n;
        return 0;
    }
    int h,l;
    l=num/n+1;
    if(l%2==1) h=num%n;
    else h=n-(num%n)+1;
    //cout << num << " " ;
    cout << l << " " << h;
}
