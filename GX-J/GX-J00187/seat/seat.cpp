#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
vector<pair<int,int> > v;
int n,m;
bool cmp(pair<int,int> a,pair<int,int> b){return a.x>b.x;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1,a;i<=n*m;i++){
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=n*m;i++){
        if(v[i-1].y==1){
            cout<<(i+n-1)/n<<" ";
            if(i%n==0)cout<<((i/n)%2?n:1);
            else{
                if(((i+n-1)/n)%2)cout<<i%n;
                else cout<<n-i%n+1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
