#include<bits/stdc++.h>
using namespace std;
int t;
const int MAXN=100005;
int a[MAXN][5];
int fen[MAXN];
struct node{
    int u;
    int v;
    int w;
    bool operator < (node &o){
        return w<o.w;
    }
};
node pai[MAXN*2];
void solve(){
    int n;
    cin>>n;
    int maxm=n/2;
    vector<int> x1;
    vector<int> x2;
    vector<int> x3;
    for (int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
            fen[i]=1;
            x1.push_back(i);
        }
        else{
            if (a[i][2]>=a[i][3]){
                fen[i]=2;
                x2.push_back(i);
            }
            else{
                fen[i]=3;
                x3.push_back(i);
            }
        }
    }
    int l1=x1.size();
    int l2=x2.size();
    int l3=x3.size();
    if (l1>maxm){
        int j=1;
        for (int z=0;z<l1;z++){
            int i=x1[z];
            node tmp;
            tmp.u=i;
            tmp.v=2;
            tmp.w=a[i][1]-a[i][2];
            pai[j]=tmp;
            tmp.u=i;
            tmp.v=3;
            tmp.w=a[i][1]-a[i][3];
            j++;
            pai[j]=tmp;
            j++;
        }
        j--;
        sort(pai+1,pai+j+1);
        for (int i=1;i<=j;i++){
            node tmp=pai[i];
            if (fen[tmp.u]!=1){
                continue;
            }
            fen[tmp.u]=tmp.v;
            if (tmp.v==2){
                l2++;
            }
            else{
                l3++;
            }
            l1--;
            if (l1<=maxm){
                break;
            }
        }
    }
    if (l2>maxm){
        int j=1;
        for (int z=0;z<l2;z++){
            int i=x2[z];
            node tmp;
            tmp.u=i;
            tmp.v=3;
            tmp.w=a[i][2]-a[i][3];
            pai[j]=tmp;
            j++;
            tmp.v=1;
            tmp.w=a[i][2]-a[i][1];
            pai[j]=tmp;
            j++;
        }
        j--;
        sort(pai+1,pai+j+1);
        for (int i=1;i<=j;i++){
            node tmp=pai[i];
            if (fen[tmp.u]!=2){
                continue;
            }
            if (tmp.v==1&&l1==maxm){
                continue;
            }
            fen[tmp.u]=tmp.v;
            if (tmp.v==1){
                l1++;
            }
            else{
                l3++;
            }
            l2--;
            if (l2<=maxm){
                break;
            }
        }
    }
    if (l3>maxm){
        int j=1;
        for (int z=0;z<l3;z++){
            int i=x3[z];
            node tmp;
            tmp.u=i;
            tmp.v=1;
            tmp.w=a[i][3]-a[i][1];
            pai[j]=tmp;
            j++;
            tmp.v=2;
            tmp.w=a[i][3]-a[i][2];
            pai[j]=tmp;
            j++;
        }
        j--;
        sort(pai+1,pai+j+1);
        for (int i=1;i<=j;i++){
            node tmp=pai[i];
            if (fen[tmp.u]!=3){
                continue;
            }
            if (tmp.v==1&&l1==maxm){
                continue;
            }
            if (tmp.v==2&&l2==maxm){
                continue;
            }
            fen[tmp.u]=tmp.v;
            if (tmp.v==1){
                l1++;
            }
            else{
                l2++;
            }
            l3--;
            if (l3<=maxm){
                break;
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans+=a[i][fen[i]];
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++){
        solve();
    }
return 0;
}
