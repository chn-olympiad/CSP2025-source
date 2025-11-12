#include<iostream>
#include<map>

using namespace std;

const int N=998244353;

int n;
int ans=0;
int a[5010];
int v[5010];

void dfs(){

}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n;
    if(n<=3){
        if(n<3){
            printf("0");
            return 0;
        }
        int x,y,z;
        cin>>x>>y>>z;
        if(x+y+z>z*2)
            ans++;
        if(x+y+z>y*2)
            ans++;
        if(x+y+z>x*2)
            ans++;
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }

    dfs();

    printf("%d",ans);

    return 0;
}
