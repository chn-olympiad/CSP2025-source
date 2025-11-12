#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
int a[500005];
struct node{
    int l,r;
};
//1 ≤ n ≤ 5 × 10^ 5 ,0 ≤ k < 2^20 ;
//对于所有 1 ≤ i ≤ n,均有 0 ≤ a [i] < 2^20 。
bool cmp(node x,node y){
    return x.r<y.r;
}
vector<int> g[2000005];
node b[500005];
int cnt,cnt2,w;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            w=1;
        }
    }
    if(w==0){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    if(a[i+1]==1){
                        i=i+1;
                        cnt++;
                    }
                }else{
                    cnt++;
                }
            }
            cout<<cnt;
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
            cout<<cnt;
        }
        return 0;
    }else if(n>=300000){
        int summ=0;
        for(int i=1;i<=n;i++){
                summ^=a[i];
            g[summ].push_back(i);
        }
        int pos=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[k^pos].size();j++){
                int u=g[k^pos][j];
                if(u>=i){
                    b[++cnt]=(node){i,u};
                }
            }
            pos^=a[i];
        }
        sort(b+1,b+cnt+1,cmp);
        //cout<<n<<" "<<cnt;
    int posr=0;
    for(int i=1;i<=cnt;i++){
        if(posr<b[i].l){
            posr=b[i].r;
            cnt2++;
            //printf("%d %d \n",b[i].r,b[i].l);
        }
    }
        cout<<cnt2;
        return 0;
    }
    int pos=0;
    for(int i=1;i<=n;i++){
        pos=0;
        for(int j=i;j<=n;j++){
            pos^=a[j];
            if(pos==k){
                b[++cnt]=(node){i,j};
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    sort(b+1,b+cnt+1,cmp);
    int posr=0;
    for(int i=1;i<=cnt;i++){
        if(posr<b[i].l){
            posr=b[i].r;
            cnt2++;
        }
    }
    cout<<cnt2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
