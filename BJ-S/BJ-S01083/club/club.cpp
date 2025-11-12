#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
struct node{
    int st,nd,maxm;
}b[N];
int n,maxx=0;
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
    if(x==n+1){
        maxx=max(maxx,sum);
        return;
    }
    if(cnt1<n/2) dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
    if(cnt2<n/2) dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
    if(cnt3<n/2) dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
}
bool cmp(node x,node y){
    return x.maxm>y.maxm;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n>=200){
            memset(b,0,sizeof(b));
            for(int i=1;i<=n;i++){
                cin>>b[i].st>>b[i].nd>>b[i].maxm;
                b[i].maxm=abs(b[i].st-b[i].nd);

            }
            sort(b+1,b+n+1,cmp);
            int ccc1=0,ccc2=0,summ=0;
            for(int i=1;i<=n;i++){
                if(ccc2>=n/2){
                    ccc1++;
                    summ+=b[i].st;
                }else if(ccc1>=n/2){
                    ccc2++;
                    summ+=b[i].nd;
                }else if(b[i].st==b[i].nd){
                    if(ccc2>ccc1){
                        ccc1++;
                        summ+=b[i].st;
                    }else{
                        ccc2++;
                        summ+=b[i].nd;
                    }
                }else if(b[i].st>b[i].nd){
                    ccc1++;
                    summ+=b[i].st;
                }else{
                    ccc2++;
                    summ+=b[i].nd;
                }
            }
            cout<<summ<<endl;
        }else{
            for(int i=1;i<=n;i++){
                cin>>a[i][1]>>a[i][2]>>a[i][3];
            }
            dfs(1,0,0,0,0);
            cout<<maxx<<endl;
        }
        maxx=0;


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
