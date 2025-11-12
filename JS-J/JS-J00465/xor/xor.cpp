#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pair pair<int,int>
using namespace std;
const int mx=5e5+5;
int a[mx];
int s[mx];
pair d[mx];
int n,k;
vector<int> g;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int f=s[j]^s[i-1];
            if(f==k){
                d[i]=make_pair(i,j);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i].second==0) continue;
        int ind=lower_bound(g.begin(),g.end(),d[i].first)-g.begin();
        if(ind==g.size()) g.push_back(d[i].second);
        else g[ind]=d[i].second;
    }
    printf("%d",g.size());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
