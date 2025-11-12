#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    int resultforlittleR = a[1];
    int newn = n*m;
    sort(a+1,a+newn+1,cmp);
    int newi = 0;
    for(int i = 1;i <= newn;i++){
        if(a[i]==resultforlittleR){
            newi = i;
            break;
        }
    }
    double temp1 = newi * 1.0 / n;
    int tempa = floor(temp1);
    int tempb = ceil(temp1);
    int c = 0,r = 0;
    if(tempb%2==0){
        c = tempb;
        r = n + 1 - (newi - tempa*n);
    }
    else{
        c = tempb;
        r = newi - tempa*n;
    }
    if(r == 0) r = n;
    cout << c << " " << r;
}
