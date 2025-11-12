#include<iostream>
#include<algorithm>
using namespace std;
long long n,maxn=-1,t;
long long s[5],a[100005][5],c1[100005];
long long maxi[100005];
bool vis[100005];
struct ao{
    long long s;
    int l;
}a1[100005];
struct bo{
    long long s;
    int l;
}b1[100005];
bool oa(ao x,ao y){
    return x.s>y.s;
}
bool ob(bo x,bo y){
    return x.s>y.s;
}
bool o(long long x,long long y){
        return x>y;
}
void f(long long x,long long sum){
    if(x>n){
        maxn=max(maxn,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(s[i]<n/2){
            s[i]++;
            f(x+1,sum+a[x][i]);
            s[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ez=0,sz=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                maxi[i]=max(maxi[i],a[i][j]);
                if(j==1){
                    a1[i].s=a[i][j];
                    a1[i].l=i;
                }
                if(j==2){
                    b1[i].s=a[i][j];
                    b1[i].l=i;
                }/*
                if(j==3){
                    c1[i]=a[i][j];
                }*/
                if(a[i][j]==0){
                    if(j==2){
                        ez++;
                    }
                    if(j==3){
                        sz++;
                    }
                }
            }

        }

            if(ez==sz&&sz==n){
                long long sum=0;
                sort(maxi+1,maxi+1+n,o);
                for(int i=1;i<=n/2;i++){
                    sum+=maxi[i];
                }
                cout<<sum<<endl;
            }
        else{
            f(1,0);
            cout<<maxn<<endl;
            maxn=-1;
        }
    }
    return 0;
}
