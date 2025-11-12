#include<bits/stdc++.h>
using namespace std;

int t;
int as,n;
int mx,mxi;
int a[100010][5];
vector<int> v[5];
int next1(int x){ return x%3+1; }
int next2(int x){ return (x+1)%3+1; }
int cha(int x,int k){
    return a[x][k]-max(a[x][next1(k)],a[x][next2(k)]);
}
bool cmp(int x,int y){
    return cha(x,mxi)<cha(y,mxi);
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);

    while(t--){
        as = 0;
        v[1].clear();
        v[2].clear();
        v[3].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                v[1].push_back(i);
                as += a[i][1];
                //printf("%d add 1\n",i);
            }
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                v[2].push_back(i);
                as += a[i][2];
                //printf("%d add 2,2 size %d\n",i,v[2].size());
            }
            else{
                v[3].push_back(i);
                as += a[i][3];
                //printf("%d add 3\n",i);
            }//
        }
        mx=0;
        for(int i=1;i<=3;i++){
            //printf("%d size %d,mx %d,if %d\n",i,v[i].size(),mx,4>-10);
            if(v[i].size() > mx){
                mx = v[i].size();
                mxi = i;
            }
            //printf("%d mx: %d %d\n",i,mx,mxi);
        }
        if(mx*2 <= n){
            printf("%d\n",as);
            continue;
        }
        sort(v[mxi].begin(),v[mxi].end(),cmp);
        for(int i=0;mx*2>n;i++){
            as -= cha(v[mxi][i],mxi);
            mx--;
        }
        printf("%d\n",as);
    }

    return 0;
}
