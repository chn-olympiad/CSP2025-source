#include<iostream>
#include<algorithm>
using namespace std;
int T;
int n;
int tot=1;
int x,y,z;
long long ans=0;
bool repeat[100005];
short pl[100005];
int num[100005];
int love[100005][4];
struct inter{
    int vlue;
    int id;
    int clb;
}a[300005];
void clean(){
    ans=0;
    for(int i=0;i<=n;i++){
        repeat[i]=0;
        pl[i]=0;
    }
}
bool cmp(inter x,inter y){
    if(x.vlue!=y.vlue){
        return x.vlue<y.vlue;
    }else{
        return x.id<y.id;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==2){
            cin>>x>>y>>z;
            int i,j,k;
            cin>>i>>j>>k;
            cout<<max(max(max(max(max(z+i,z+j),y+k),y+i),x+k),x+j)<<endl;
        }else{
        clean();
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            int maxn=max(x,max(y,z));
            int minn=min(x,min(y,z));
            love[i][1]=minn;
            if(x!=minn&&x!=maxn){
                love[i][2]=x;
            }
            if(z!=minn&&z!=maxn){
                love[i][2]=z;
            }
            if(y!=minn&&y!=maxn){
                love[i][2]=y;
            }
            love[i][3]=maxn;
            ans+=maxn;
            a[tot].clb=1;
            a[tot].id=i;
            a[tot].vlue=x-maxn;
            tot++;
            a[tot].clb=2;
            a[tot].id=i;
            a[tot].vlue=y-maxn;
            tot++;
            a[tot].clb=3;
            a[tot].id=i;
            a[tot].vlue=z-maxn;
            tot++;
        }
        sort(a+1,a+tot+1,cmp);
        for(int i=1;i<=tot;i++){
            if(pl[a[i].id]==2){
                if(num[a[i].clb]<n/2){
                    ans+=a[i].vlue;
                    num[a[i].clb]++;
                    pl[a[i].id]++;
                }else{
                    ans+=love[a[i].id][2];
                }
            }else if(a[i].vlue==a[i+1].vlue&&a[i].id==a[i+1].id){
                if(a[i+1].vlue==a[i+2].vlue&&a[i+2].id==a[i+1].id){
                    ans+=a[i+1].vlue;
                    i+=2;
                    pl[a[i].id]+=3;
                }else if(pl[a[i].id]==1){
                    ans+=a[i+1].vlue;
                    i+=1;
                    pl[a[i].id]+=2;
                }else{
                    pl[a[i].id]+=2;
                }
            }else{
                pl[a[i].id]++;
            }
        }
        cout<<ans<<endl;
        }

    }
}

