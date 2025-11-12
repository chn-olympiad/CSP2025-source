#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e5;
struct men{
    int s;
    int number;
}Map[25][25];
ll num=1;
struct man{
    int s;
    int number;
}s[N];
ll n,m;
bool wyb(man a,man b){
	return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>s[i].s;
        s[i].number=i;
    }
    ll a1=n*m;
    sort(s+1,s+1+a1,wyb);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int k=1;k<=n;k++){
                Map[i][k].number=s[num].number;
                num++;
            }
        }else{
            for(int j=n;j>0;j--){
                Map[i][j].number=s[num].number;
                num++;
            }
        }
    }
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Map[i][j].number==1){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
