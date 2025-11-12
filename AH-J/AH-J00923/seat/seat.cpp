#include<bits/stdc++.h>
using namespace std;
int cnt[1001];
bool cmp(const int x1,const int x2){
    return x1>x2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>cnt[i];
        if(i==1)x=cnt[i];
    }
    sort(cnt+1,cnt+1+n*m,cmp);
    int i=1,j=1,num=1,si=0;
    for(int i=1;i<=n;i++){
        if(si==0){
            while(j<=n){
                if(cnt[num]==x)cout<<i<<" "<<j;
                j++;
                num++;
            }
            j=n;
        }
        else {
            while(j>=1){
                if(cnt[num]==x)cout<<i<<" "<<j;
                j--;
                num++;
            }
            j=1;
        }
        si=(1-si);
    }
    return 0;
}
