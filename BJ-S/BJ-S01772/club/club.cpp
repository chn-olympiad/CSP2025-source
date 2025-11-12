#include<bits/stdc++.h>

#define int long long

const int N=100005;

int a[3][N],p[N];

int n;
int ans;
int c[3];
void run(){
    std::cin>>n;
    ans=0,c[0]=c[1]=c[2]=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[0][i]>>a[1][i]>>a[2][i];
        if(a[0][i]>a[1][i]&&a[0][i]>a[2][i]){
            ans+=a[0][i]; c[0]++; p[i]=0;
        }else if(a[1][i]>a[2][i]){
            ans+=a[1][i]; c[1]++; p[i]=1;
        }else{
            ans+=a[2][i]; c[2]++; p[i]=2;
        }
    }
    int x=-1;
    for(int i=0;i<3;i++) if(c[i]>n/2) x=i;
    if(~x){
        std::vector<int> vec;
        for(int i=1;i<=n;i++){
            if(p[i]==x){
                int sati=0;
                for(int j=0;j<3;j++){
                    if(j!=x) sati=std::max(sati,a[j][i]);
                }
                vec.push_back(sati-a[x][i]);
            }
        }
        std::sort(vec.begin(),vec.end());
        while(vec.size()>n/2){
            ans+=vec.back();
            vec.pop_back();
        }
    }
    std::cout<<ans<<'\n';

    return;
}

int T;
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    std::cin>>T; while(T--) run();

    return 0;
}
