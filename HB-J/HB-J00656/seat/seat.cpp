#include <bits/stdc++.h>
using namespace std;
int a[1000],cup[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,cnt=0,x,temp,si,sj;
    cin>>n>>m;
    for(long long i=0;i<n*m;i++){
        cin>>a[i];
        cup[i]=1;
        cnt+=1;
    }
    x=a[0];
    long long cot=cnt;
    for(int i=cot-1;i>=0;i--){
        if(cnt==0) break;
        else{
            if(cup[i]==1){
                a[cot-cnt]=i+1;
                cnt--;

            }
        }
    }
    for(long long i=0;i<cot;i++){
        if(a[i]==x){
            temp=i+1;
        }
    }
    long long br=n*2;
    if(temp%br==0){
        si=1;
        sj=temp/br*2;
    }
    else if(temp%br>n){
        si=br-temp%br+1;
        sj=temp/br*2+2;
    }
    else if(temp%br<=n) {
        si=temp%br;
        sj=temp/br*2+1;
    }
    cout<<sj<<' '<<si;
    return 0;
}
