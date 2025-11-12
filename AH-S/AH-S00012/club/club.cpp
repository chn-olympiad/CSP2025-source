#include<bits/stdc++.h>
using namespace std;
/*
不是我学了一年谁能告诉我这第一题是什么鬼东西？？？
阿卡伊新专辑的第一首都没有这么阴

喵喵我要开始打神秘部分分代码了

对于所有特殊性质A：
直接统计看是不是都是0

对于所有的特殊性质B：
直接看哪个大分给谁

对于特殊性质C：
拿我的神秘代码跑一跑试试
对于C我的理解是保证不会有重复的数字，似乎能过
5的大样例过了
听天由命吧

期望得分：20～30


再仔细思考，我们不妨dfs暴搜一下，直接枚举每一个人分到那里
枚举每一个人的三种选择也就三3^n,
能过前4个点，期望得分20

现在T1的期望得分:40~50
*/
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=1e5+5;
int T,n,ans;
struct yi{
	int a,b,c,id;
	bool operator < (const yi &rhs)const {
        if(a==rhs.a){
            if(b==rhs.b){
                return c<rhs.c;
            }
            return b<rhs.b;
        }
		return a>rhs.a;
	}
}x[N];
struct er{
	int a,b,c,id;
	bool operator < (const er &rhs)const {
	    if(b==rhs.b){
            if(a==rhs.a){
                return c<rhs.c;
            }
            return a<rhs.a;
        }
		return b>rhs.b;
	}
}y[N];
struct san{
	int a,b,c,id;
	bool operator < (const san &rhs)const {
	    if(c==rhs.c){
            if(b==rhs.b){
                return a<rhs.a;
            }
            return b<rhs.b;
        }
		return c>rhs.c;
	}
}z[N];
bool vis[N];
int maxn;
inline void dfs(int cur,int t,int cnt1,int cnt2,int cnt3,int maxs){
    if(cur>n){//边界
        ans=max(ans,maxs);
        return ;
    }
    //还在走
    if(t==1){
        if(cnt1+1>maxn){
            return ;
        }
        else{
            maxs+=x[cur].a;
            ans=max(ans,maxs);
            for(int i=1;i<=3;i++){
                dfs(cur+1,i,cnt1+1,cnt2,cnt3,maxs);
            }
        }
    }
    else if(t==2){
        if(cnt2+1>maxn){
            return ;
        }
        else{
            maxs+=x[cur].b;
            ans=max(ans,maxs);
            for(int i=1;i<=3;i++){
                dfs(cur+1,i,cnt1,cnt2+1,cnt3,maxs);
            }
        }
    }
    else if(t==3){
        if(cnt3+1>maxn){
            return ;
        }
        else{
            maxs+=x[cur].c;
            ans=max(ans,maxs);
            for(int i=1;i<=3;i++){
                dfs(cur+1,i,cnt1,cnt2,cnt3+1,maxs);
            }
        }
    }
    return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		int cnt1,cnt2,cnt3;
		cnt1=cnt2=cnt3=ans=0;
		n=read();
		maxn=n/2;
		if(n<=10){
            for(int i=1;i<=n;i++){
                x[i].a=read();x[i].b=read();x[i].c=read();
            }
            for(int i=1;i<=3;i++){
                dfs(1,i,0,0,0,0);
            }
            write(ans);
            puts("");
		}
		else{
            bool f1=1,f2=1;
            for(int i=1;i<=n;i++){
                x[i].a=read();x[i].b=read();x[i].c=read();
                if(x[i].b!=0){
                    f1=0;
                }
                if(x[i].c!=0){
                    f2=0;
                }
                y[i].a=z[i].a=x[i].a;
                y[i].b=z[i].b=x[i].b;
                y[i].c=z[i].c=x[i].c;
                x[i].id=y[i].id=z[i].id=i;
            }
            if(f1&&f2){//solve A
                sort(x+1,x+n+1);
                for(int i=1;i<=maxn;i++){
                    ans+=x[i].a;
                }
                write(ans);
                puts("");
                continue;
            }
            else if(f2){//solve B
                for(int i=1;i<=n;i++){
                    if(x[i].a>x[i].b){
                        ans+=x[i].a;
                    }
                    else{
                        ans+=x[i].b;
                    }
                }
                write(ans);
                puts("");
                continue;
            }
            int lx=1,ly=1,lz=1;
    /*
            puts("x");
            for(int i=1;i<=n;i++){
                cout<<x[i].a<<' '<<x[i].id<<endl;
            }
            puts("y");
            for(int i=1;i<=n;i++){
                cout<<y[i].a<<' '<<y[i].id<<endl;
            }
            puts("z");
            for(int i=1;i<=n;i++){
                cout<<z[i].a<<' '<<z[i].id<<endl;
            }
    */
            while(lx<=n||ly<=n||lz<=n){
                /*for(int i=1;i<=n;i++){
                    cout<<vis[i]<<' ';
                }*/
                //cout<<endl;
                while(vis[x[lx].id])lx++;
                while(vis[y[ly].id])ly++;
                while(vis[z[lz].id])lz++;
                if(x[lx].a>=y[ly].b&&x[lx].a>=z[lz].c&&!vis[x[lx].id]&&cnt1<=maxn){
                    //cout<<"x "<<x[lx].a<<' '<<x[lx].id<<endl;
                    ans+=x[lx].a;
                    cnt1++;
                    vis[x[lx].id]=1;
                    lx++;
                }
                else if(y[ly].b>=x[lx].a&&y[ly].b>=z[lz].c&&!vis[y[ly].id]&&cnt2<=maxn){
                    //cout<<"y "<<y[ly].b<<' '<<y[ly].id<<endl;
                    ans+=y[ly].b;
                    cnt2++;
                    vis[y[ly].id]=1;
                    ly++;
                }
                else if(z[lz].c>=y[ly].b&&z[lz].c>=x[lx].a&&!vis[z[lz].id]&&cnt3<=maxn){
                    //cout<<"z "<<z[lz].c<<' '<<z[lz].id<<endl;
                    ans+=z[lz].c;
                    cnt3++;
                    vis[z[lz].id]=1;
                    lz++;
                }
            }
            write(ans);
            puts("");
		}
    }
	return 0;
}
