#include <bits/stdc++.h>
using namespace std;
const int MAXN(1e3+5);
int a[MAXN];
struct Node{
    int l;int r;
};
vector<Node> b;//qujian

bool cmp(Node a,Node b){
    return a.r<b.r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //k->2^20
    int n,k;
    cin>>n>>k;
    if(n>1000){
        //Special B
        int sum1=0,sum0=0;
        for(int i=1;i<=n;i++){
            int asd;
            cin>>asd;
            if(asd)sum1++;
            else sum0++;
        }
        if(k==1){
            cout<<sum1;
        }else{
            cout<<sum0;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)b.push_back({i,i});
    }
    //O(n3)
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long sum=0;
            for(int k=i;k<=j;k++){
                sum^=a[k];
            }
            if(sum==k){
                b.push_back({i,j});
            }
        }
    }
   sort(b.begin(),b.end(),cmp);
   long long ans=0;
   int last=0;
   for(int i=0;i<b.size();i++){
        if(b[i].l>last){
            ans++;
            last=b[i].r;
        }
   }
   cout<<ans;
    return 0;
}

