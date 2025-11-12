#include <bits/stdc++.h>
using namespace std;

long long  n,m,k;
long long cnt;
long long join;
long long ans;

struct Road{
    long long a;
    long long b;
    long long v;
};

Road road[1111111];
long long bcj[111111];
long long c[111];

long long serchup(long long x){
    if(x == bcj[x])return x;
    bcj[x] = serchup(bcj[x]);
    return bcj[x];
}
bool serch(long long x,long long y){
    if(serchup(x) == serchup(y))return 1;
    return 0;
}

void uni(long long x,long long y){
    bcj[x] = bcj[y];
}


bool abc(Road x,Road y){
    if(x.v < y.v)return 1;
    return 0;
}

long long xctg[20][11111];//if >= 2:Yes else no
long long xc[20][11111];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cnt++;
        cin >> road[i].a >> road[i].b >> road[i].v;
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cnt++;
            cin >> road[cnt].v;
            road[cnt].a = n + i;// node = n + k
            road[cnt].b = j;

            xc[i][j] = road[cnt].v;
        }
    }
    //for()
    sort(road + 1,road + n + k + 1,abc);
    for(int i = 1;i <= n + k;i++){
        bcj[i] = i;
    }
    join = n + k - 1;
    for(int i = 1;join;i++){
        if(serch(road[i].a,road[i].b) == 0){
            uni(road[i].a,road[i].b);
            ans = ans + road[i].v;
            join--;


            //cout << road[i].v << endl;

  
            if(road[i].a > n){
                xctg[road[i].a - n][road[i].b] = 1;
                xctg[road[i].a - n][0]++;
            }
        }
    }
    for(int i = 1;i <= k;i++){
        if(xctg[i][0] == 1){
            for(int j = 1;j <= n;j++){
                if(xctg[i][j] == 1){
                    ans = ans - xc[i][j];
                    //cout <<endl << "2345" << endl;
                }
            }
        }
    }

    for(int i = 1;i <= n;i++){
        //cout << bcj[i] << " ";
    }//cout << endl;

    
    
    
    //cout << endl << 

    cout << ans;
    return 0;
}
