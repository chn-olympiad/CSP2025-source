#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n,k;
int a[MAXN];
int s[MAXN];
long long ans=0;
bool vis[MAXN];
struct aaa{
    int l,r;
    bool operator <(const aaa &x) const{
        return (r-l+1)<(x.r-x.l+1);
    }
};
vector<aaa>line;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    memset(vis,false,sizeof(vis));
    bool is_01 = true;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i] = s[i-1] ^ a[i];
        if(a[i]!=0&&a[i]!=1){
            is_01 = false;
        }
        if(a[i]==1){
			cnt++;
		}
    }
    if(is_01){
       if(k==0){
			printf("%d\n",n-cnt);
	   }
		else{
			printf("%d\n",cnt);
		}
        return 0;
    }
    if(n<=1000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int w = s[j]^s[i-1];
                if(w==k){
                    line.push_back({i,j});
                }
            }
        }
        sort(line.begin(),line.end());
        for(auto i:line){
            int l = i.l;
            int r = i.r;
            bool flag = false;
            for(int i=l;i<=r;i++){
                if(vis[i]){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            for(int i=l;i<=r;i++){
                vis[i] = true;
            }
            ans++;
        }
        printf("%lld\n",ans);
        return 0;
    }
    return 0;
}
