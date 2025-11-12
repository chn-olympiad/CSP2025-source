//luogu uid: 1411407  yyc_Yae_Miko(blue(???bushi, what are you shouting. Speak!) name)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
using namespace std;
int rd(){
    int x=0,f=1;char c;
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-'){f=-1;c=getchar_unlocked();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c&15);c=getchar_unlocked();}
    return x*f;
}
const int mod=998244353;
int a[5005];
bool Yae_Miko[5005];//useless and meaningless...
int ans=0;
int n;
void dfs(int pos,int cnt,int sum,int mx){
    if(pos>n&&cnt>=3&&sum>2*mx){
        ans=(ans+1)%mod;
        return;
    }
    if(pos>n)return;
    dfs(pos+1,cnt+1,sum+a[pos],max(mx,a[pos]));
    dfs(pos+1,cnt,sum,mx);
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    //freeopen("polygon.in","r",stdin);
    //freeopen("polygon.out","w",stdout);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);//What a difficulty problem it is...
    n=rd();
    for(int i=1;i<=n;i++)a[i]=rd();
    if(n<3){//12pts(task 1~3)
        cout<<0;
        return 0;
    }else if(n==3){
        int sum=0,mx=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        if(sum>2*mx){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    dfs(1,0,0,0);//28pts(task4~10)
    cout<<ans;
    return 0;
}
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//
//f??? ??? <-meaningless...
//data:
//9:13a.m. T1&T2 complete  add 150~200pts                                    (about 150~200 pts)
//10:25a.m. T3 complete    add 60~80pts                                      (about 210~280 pts)
//10:31a.m. I look at T4 about 114 times, but I don't understand             (about 210~280 pts)
//10:43a.m. I look at T4 about 514 times, but I don't understand  add 12pts  (about 222~292 pts)
//11:02a.m. I look at T4 about 1919 times, I want to use dfs now  add 28pts  (about 240~308 pts)
//11:28a.m. I look at T4 about 8100 times, I want to sleep(qwq)              (about 240~308 pts)
//11:33a.m. Oh, no! I see 10^6 as 10^3(T1), I'm a stupid
//11:45a.m. How boring...
//```markdown
//~~I look at T4 about $\Huge \color{red}1145141919810$ times of all!!!~~
//```
