#include <bits/stdc++.h>
using namespace std;

const int MAXn = 1e4+20;
const int MAXm = 1e6+2;

struct E{

    int x,y,w;
};

bool cmp(E &a,E &b){

    return a.w<b.w;
}

int n,m,k,fa[MAXn],ans = 0,town[12][MAXn],c[12];//i's boss is fa[i]
E g[MAXm];


int Find(int x){

    if(fa[x] == x){
        return x;
    }
    else{
        
        fa[x] = fa[fa[x]];
        return Find(fa[x]);
    }
}


int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    
    
    cin>>n>>m>>k;

    for(int i = 1;i<=n;i++){

        fa[i] = i;
    }



    int x,y,w;
    
    for(int i = 1;i<=m;i++){

        cin>>g[i].x>>g[i].y>>g[i].w;
    }



    for(int i = 1;i<=k;i++){
        
        cin>>c[i];
        if(c[i] == 0){

            for(int j = 1;j<=n;j++){
                cin>>town[i][j];

                if(town[i][j] == 0){
                    
                    n++;
                    m++;
                    E newpoint;
                    newpoint.x = n;
                    newpoint.y = j;
                    newpoint.w = 0;

                    g[m] = newpoint;
                }
            }
            
        }
        

        
    }

    sort(g+1,g+1+m,cmp);

    int cnt = 0;

    for(int i = 1;i<=m;i++){
        

        int R1 = Find(g[i].x);
        int R2 = Find(g[i].y);

        if(R1 != R2){

            fa[R1] = R2;
            cnt++;
            ans+=g[i].w;

        }

        if(cnt == n-1) break;
    }



    cout<<ans<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}


/*

5 6 0
1 4 3
1 2 1
2 4 5
1 3 7
3 5 6
4 5 2


4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


*/