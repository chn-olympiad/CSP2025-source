#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FRR freopen("seat.in","r",stdin)
#define FRW freopen("seat.out","w",stdout)
int n,m;
struct stu{
    int d,p;
}a[110];
bool cmp(const stu &x,const stu &y){
    return x.d>y.d;
}
signed main(){
    FRR;
    FRW;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].d;
        a[i].p=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int p;
    for(int i=1;i<=n*m;i++){
        if(a[i].p==1){
            p=i;
            break;
        }
    }
    cout<<(p-1)/n+1<<" "<<(((p-1)/n+1)%2==1 ? ((p-1)%n+1) : n-((p-1)%n));
	return 0;
}
