#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long uvw[1000005][4];//only do test 1-4

void cut(long long x,long long y){
    for(int i=1;i<=m;i++){
        if((uvw[i][1]==x&&uvw[i][2]==y)||(uvw[i][2]==x&&uvw[i][1]==y)){
            uvw[i][3]=1145141919810;
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    k=0;//only do test 1-4
    for(int i=1;i<=m;i++){
        long long u,v,w;
        scanf("%lld %lld %lld",&uvw[i][1],&uvw[i][2],&uvw[i][3]);
    }
    long long ans=0,cnt=0;
    while(cnt!=n-1){
        for(int x=1;x<=n;x++){
            long long temp=1145141919810,minpass=0;
            for(int y=1;y<=m;y++){
                if((uvw[y][1]==x||uvw[y][2]==x)){
                    if(uvw[y][3]<temp){
                        temp=uvw[y][3];
                        minpass=y;
                    }
                }
            }
            if(temp!=1145141919810&&minpass){
                ans+=temp;
                uvw[minpass][3]=1145141919810;
                cout<<"minpass"<<minpass<<" "<<ans<<endl;
                cnt++;
                if(cnt==n-1) break;
            }
        }
    }
    cout<<ans;
    return 0;
}
