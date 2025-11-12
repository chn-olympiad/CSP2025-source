#include <bits/stdc++.h>

using namespace std;
bool isconnected[10000][10000];
long long countryrp[10][10000];
long long country[10];
bool crisb[10][10000];

struct Road {
    int a,b;
    long long price;
};

vector<Road> roads;
bool cisb[10];
int n,m,k;
long long sum = 0;

void search() {
    for (Road road : roads) {
        if (isconnected[road.a][road.b] == false) {
            long long minPrice = road.price;
            for (int c=0;c<k;c++) {
                long long cpr = 0;
                if (cisb[c] != true) cpr += country[c];
                if (crisb[c][road.a] != true) cpr += countryrp[c][road.a];
                if (crisb[c][road.b] != true) cpr += countryrp[c][road.b];
                if (cpr <= minPrice) {
                    crisb[c][road.a] = true;
                    crisb[c][road.b] = true;
                    cisb[c] = true;
                    minPrice = cpr;
                    break;
                }

            }
            isconnected[road.a][road.b] = true;
            isconnected[road.b][road.a] = true;
            sum = sum + minPrice;
        } 
    }
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    memset(cisb,0,sizeof(cisb));
    for (int i=0;i<10;i++) {
        memset(crisb[i],0,sizeof(crisb[i]));
    }

    for (int i=0;i<n;i++) {
        memset(isconnected[i],0,sizeof(isconnected[i]));
    }
    for (int i=0;i<m;i++) {
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        Road r;
        r.a = a;
        r.b = b;
        r.price = c;
        roads.push_back(r);
    }
    for (int i=0;i<k;i++) {
        scanf("%lld",&country[i]);
        for (int j=0;j<n;j++) {
            scanf("%lld",&countryrp[i][j]);
        }
    }
    search();
    printf("%lld",sum);
    return 0;
}
