#include<bits/stdc++.h>
using namespace std;
struct fg{
	int a,b,c;
};long long M;
void dfs(int a,fg*h,long long sum,int cnt,fg k)
{if(k.a>a/2||k.b>a/2||k.c>a/2)return;
M=max(M,sum);
if(cnt>a)return;
dfs(a,h,sum+h[cnt].a,cnt+1,{k.a+1,k.b,k.c});
dfs(a,h,sum+h[cnt].b,cnt+1,{k.a,k.b+1,k.c});
dfs(a,h,sum+h[cnt].c,cnt+1,{k.a,k.b,k.c+1});
return;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;cin.tie(0)->sync_with_stdio(0);
	cin>>a;
	while(a--)
	{int b;cin>>b;
	fg h[b+1];
	for(int i=1;i<=b;i++)
	{cin>>h[i].a>>h[i].b>>h[i].c;}
	M=0;
	dfs(b,h,0,1,{0,0,0});
	cout<<M<<endl;
	}
	return 0;
} 
