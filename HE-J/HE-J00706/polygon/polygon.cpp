#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5005;
int a[N];
int ma(int x,int y){
    int cnt=0;
    for(int q=x;q<=y;q++){
        cnt=max(cnt,a[q]);
    }
    return cnt;
}
int su(int x,int y){
    int sum=0;
    for(int q=x;q<=y;q++){
        sum+=a[q];
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int q=1;q<=n;q++){
        cin>>a[q];
    }
    int sum=0;
    for(int q=1;q<=n;q++){
        for(int w=q;w<=n;w++){
            int t=ma(q,w);
            int cnt=su(q,w);
            if(t*2<=cnt){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
