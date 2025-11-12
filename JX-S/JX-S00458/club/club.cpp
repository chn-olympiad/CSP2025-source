#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[100005][3],tmp[100005],ans,s[3];
vector<int> vec;
void solve(){
    scanf("%d",&n);
    ans=s[0]=s[1]=s[2]=0;vec.clear();
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        if(a[i][0]<a[i][1]) tmp[i]=1;
        else tmp[i]=0;
        if(a[i][tmp[i]]<a[i][2]) tmp[i]=2;
        ans+=a[i][tmp[i]];
        s[tmp[i]]++;
    }
    if(s[0]>n/2){
        for(int i=1;i<=n;i++){
            if(tmp[i]==0) vec.push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
        }
    }
    if(s[1]>n/2){
        for(int i=1;i<=n;i++){
            if(tmp[i]==1) vec.push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
        }
    }
    if(s[2]>n/2){
        for(int i=1;i<=n;i++){
            if(tmp[i]==2) vec.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][0]));
        }
    }
    sort(vec.begin(),vec.end());
    int k=vec.size()-n/2;
    for(int i=0;i<k;i++) ans-=vec[i];
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//I hate this greedy problem. It took me 70 minutes to solve it!
//Also, I don't know whether the solution is correct or not, even though it passed the big example.
