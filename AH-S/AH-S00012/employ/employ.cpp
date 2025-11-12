#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
开考的三小时开T4
题意好懂，直接部分分起手

特殊性质A：
如果我没有理解错的话，这个均有的意思是全都是
所以保证每一个人都可以通过考核
所以直接算n的阶乘即可
5个点，期望得分25
？为啥给的样例没过，何意味
那就是当我理解错了吧


考虑小范围：
每一天都可以任选一个人，总时间复杂度是O(n^n)
期望8分

然后再看一个m=1的情况
只要能录取一个人即可
靠不想了

整场考试到不了100分遗憾离场
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
const int N=500+5;
const int Mod=998244353;
int n,m,c[N],ans;
string s;
bool vis[N];
void dfs(int cur,int cnt,int fal){
    if(fal+m>n)return ;
    if(cur>n){
        if(cnt>=m)ans++;
        ans=ans%Mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(c[i]<=fal){
                dfs(cur+1,cnt,fal+1);
            }
            else{
                if(s[cur]=='1')dfs(cur+1,cnt+1,fal);
                else dfs(cur+1,cnt,fal+1);
            }
            vis[i]=0;
        }
    }
    return ;
}
//111208360
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    n=read();m=read();
    cin>>s;
    bool flag=1;//标记是不是A
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')flag=0;
    }
    s=' '+s;
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    if(flag){//满足A的情况
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=((ans%Mod)*i)%Mod;
        }
        write(ans);
        return 0;
    }
    if(n<=10){
        dfs(1,0,0);
        write(ans);
        return 0;
    }
    if(m==1){//一个特殊情况
        if(s.find('1')!=string::npos){
            int wei=s.find('1');
            wei--;
            int you;
            sort(c+1,c+n+1);
            for(int i=1;i<=n;i++){
                if(c[i]>wei){
                    you=i;//第一个忍耐值>wei的人
                    break;
                }
            }
            int sum=1;
            for(int i=1;i<n;i++){
                sum=(sum*i)%Mod;
            }
            write(((sum%Mod)*(n-you+1))%Mod);
        }
        else{
            puts("0");
        }
    }
	return 0;
}
