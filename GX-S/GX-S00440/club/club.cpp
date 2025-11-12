#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int t,n;
struct str{
    int k[3];
    int j[3]={0,1,2};
    int num[3];
};
bool cmp(str x,str y){
    return x.maxx-y.maxx>x.num1-y.num1;
}
vector<str> a(1e5);
vector<int> club[3];
int f(int i){
    for(int i=0;i<3;i++){

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    ld sum;
    while(t--){
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i].k[0]>>a[i].k[1]>>a[i].k[2];
            a[i].tot=a[i].k[0]+a[i].k[1]+a[i].k[2];
            a[i].maxx=max(a[i].k[0],max(a[i].k[1],a[i].k[2]));
            a[i].minn=min(a[i].k[0],min(a[i].k[1],a[i].k[2]));
            a[i].midd=a[i].tot-a[i].maxx-a[i].minn;
            sort(a[i].k,a[i].k+3);
            a[i].num[0]=0,a[i].num[1]=1,a[i].num[2]=2;
            sort(a[i].j,a[i].j+3);
        }
        for(int i=0;i<n;i++) sum+=k[f(i)];
        for(int i=0;i<n;i++){
            if(club[a[i].num[0]].size()+1<=n/2){
                club[a[i].num[0]].push_back(i);
                sum+=a[i].k[a[i].num[0]];
            }
        }
        printf("%ld\n",sum);
    }
    return 0;
}
