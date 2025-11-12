#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=2147483647;
const ll LLINF=9223372036854775807;
const int N=100+10;
struct node{
    int v;
    int id;
};
int n,m;
node a[N];

bool cmp(node a,node b){
    if(a.v==b.v)return a.id<b.id;
    return a.v>b.v;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n>>m;
   for(int i=1;i<=n*m;i++){
        cin >> a[i].v;
        a[i].id=i;
   }
   sort(a+1,a+n*m+1,cmp);
   int tmp;
   for(int i=1;i<=n*m;i++){
        //cout << a[i].v << " "<<a[i].id<<endl;
        if(a[i].id==1){
            tmp=i;
            break;
        }
   }
   //cout << "------------------"<<endl;
   //cout << tmp<<endl;
   int x,y;
   y=(tmp+n-1)/n;
   if(y%2==0){
        x=n-(tmp-((tmp+n-1)/n-1)*n)+1;
   }
   else{
        x=tmp-((tmp+n-1)/n-1)*n;
   }
   cout <<y<<" "<<x<<endl;
}
