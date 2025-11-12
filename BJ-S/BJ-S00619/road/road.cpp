#include<bits/stdc++.h>
using namespace std;
#define int long long
int bx[1005],n,m,k,i,j;
int jj[1005][1005];
struct nd{
    int st,ed,price;
}a[1005];
int find(int x){
    if(bx[x]!=x) return find(bx[x]);
    else return x;
}

bool cmp(nd a,nd b){
    return a.price<b.price;
}
signed main(){
    memset(jj,0x3f,sizeof jj);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    if(k==0){
    for(i=1;i<=m;i++)
        cin >> a[i].st >> a[i].ed >> a[i].price;
        for(i=1;i<=n;i++)
        bx[i]=i;
        sort(a+1,a+m+1,cmp);
        int sum=0,top=1,sp=0;
        while(sum<n-1){
            if(find(a[top].st)!=find(a[top].ed)){
                bx[a[top].st]=a[top].ed;
                sum++;
                sp+=a[top].price;
            }
            top++;
        }
        cout << sp;
        }
    else{
        int st,ed,price;
        for(i=1;i<=m;i++){
            cin >> st >> ed >> price;
            jj[st][ed]=jj[ed][st]=price;
        }
        int tem[1005],e;
        cin >> e;
        for(i=1;i<=n;i++){
            cin >> tem[i];
        }
        for(i=1;i<=n-1;i++){
            for(j=i+1;j<=n;j++){
                jj[i][j]=jj[j][i]=min(jj[j][i],tem[i]+tem[j]);
            }
        }
        int top=0;
        for(i=1;i<=n-1;i++){
            for(j=i+1;j<=n;j++){
                if(jj[i][j]<0x3f3f3f3f3f3f3f3f){
                    top++;
                    a[top].st=i,a[top].ed=j;
                    a[top].price=jj[i][j];
                }
            }
        }
        for(i=1;i<=n;i++)
        bx[i]=i;
        sort(a+1,a+m+1,cmp);
        int sum=0,sp=0;
        top=1;
        while(sum<n-1){
            if(find(a[top].st)!=find(a[top].ed)){
                bx[a[top].st]=a[top].ed;
                sum++;
                sp+=a[top].price;
            }
            top++;
        }
        cout << sp;

    }
    return 0;
}
