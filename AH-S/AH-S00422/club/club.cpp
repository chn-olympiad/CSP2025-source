#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#define ll long long
#define itn int
#define scf scanf
#define prf printf
#define gc getchar
#define pc putchar
#define fu(v,s,e) for(int v=s;v<=(e);v++)
#define fd(v,s,e) for(int v=s;v>=(e);v--)
using namespace std;
int _t;
inline int in(){
    itn x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') f=-1,c=gc();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return f*x;
}
void out(int x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
inline void out(int x,char c){
    out(x),pc(c);
}
int n,a[100005][3],t[3],mxt,ans,b[100005],tot;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    _t=in();
    while(_t--){
        n=in(),t[0]=t[1]=t[2]=ans=0;
        fu(i,1,n) fu(j,0,2) a[i][j]=in();
        fu(i,1,n){
            if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) t[0]++;
            else if(a[i][1]>a[i][2]) t[1]++;
            else t[2]++;
        }
        if(t[0]>t[1]&&t[0]>t[2]) mxt=0;
        else if(t[1]>t[2]) mxt=1;
        else mxt=2;
        fu(i,1,n) ans+=max(a[i][0],max(a[i][1],a[i][2]));
        if(t[mxt]>(n>>1)){
            tot=0;
            fu(i,1,n){
                int mn=0x39393939;
                fu(j,0,2){
                    if(j==mxt) continue;
                    mn=min(mn,a[i][mxt]-a[i][j]);
                }
                if(mn>=0) b[++tot]=mn;
            }
            sort(b+1,b+1+tot);
            fu(i,1,tot-(n>>1)) ans-=b[i];
        }
        out(ans,'\n');
    }
    // cerr<<'\n'<<clock()/1000.0<<"ms\n";
    return 0;
}
/*
AFOed
自从今年省选爆炸已经半年了
OI什么的，不干了喵！！！
      ___       _________     ______
     / _ \      | _______|   / ____ \
    / / \ \     | |         / /    \ \
   / /___\ \    | |_____   | |      | |
  / _______ \   | ______|  | |      | |
 / /       \ \  | |         \ \____/ /
/_/         \_\ |_|          \______/

现在只会T1、T2了
T3应该是TLE
T4只打了n<=18的subtask，其他几个包不想写了
算法什么的基本完全忘了（就算没忘应该也做不出来T4）
----------------------------------------------------------
Phigros真好玩，就是板子掉帧，容易红温
目前rks=14.88，应该到瓶颈期了
贝多芬祝福 good1
So laggy！ good2
重生 good1
真红温
----------------------------------------------------------
以往相逢路过 最不屑唱情歌
此刻梦魇深堕 谁来真心保护我
----------------------------------------------------------
world.execute(me);
详见本人T4
----------------------------------------------------------
圆4要出力！！！
魔女之夜的回天！！！
已经鸽了好几年了
还记得我的入坑作就是魔圆喵
----------------------------------------------------------
虽然很想再写一句f*** **F，但想想还是算了
毕竟上面这种写法懂得都懂
----------------------------------------------------------
想成为轻小说男主
----------------------------------------------------------
喵喵喵～
喵～
喵～
喵～
喵～
喵～
*/