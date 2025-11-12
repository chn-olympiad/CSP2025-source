#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;


int sum,dl,n;
struct club{
    int a,b,c;
}p[maxn];

bool cmp(club e1,club e2){
    return e1.a>e2.a;
}
int bsum = 0;
int aa=0,bb=0,cc=0;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;

    for(int i=1;i<=t;i++){

        memset(p,0,sizeof(p));

        //memset(viss,0,sizeof(viss));
        //memset(c,0,sizeof(c));
        aa=0,bb=0,cc=0;
        cin >> n;
        sum = 0;
        dl = n/2;
        for(int j=1;j<=n;j++){
            int x,y,z;
            cin>>x>>y>>z;
            p[j].a = x;
            p[j].b = y;
            p[j].c = z;
        }
        sort(p+1,p+n+1,cmp);


        for(int j=1;j<=dl;j++){
            sum+=p[j].a;
        }
        cout << sum << endl;
    }
    return 0;
}
