#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    long long n,m,score[100005],R,c,r;
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        cin >> score[i];
    }
    R = 1;
    for(int j = 2;j<=n*m;j++){
        if(score[1] < score[j]){
            R++;
        }
    }
    if(R%2==0)r = R%(m+1);
    else r = R%m;
    if(r == 0)r = n;
    c = R/n;
    if(R/n!=0)c+=1;
    cout << c << " " << r;
    return 0;
}
