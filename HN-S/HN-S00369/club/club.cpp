#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
int t,n,ans,tong[100010],tot[4],cnt1,cnt2,cnt3,maxx,flag1,flag2;
struct node{
	int num,bo,ren;
}a[500010],b[100010],c[100010];
bool cmp(node i,node j){
	if(i.num==j.num){
		return i.bo<j.bo;
	}	
	return i.num>j.num;
}
void dfs(int u,int sum,int tmp1,int tmp2,int tmp3){
	if(u==n+1){
		maxx=max(maxx,sum);
		return;
	}
	if(tmp1!=n/2) dfs(u+1,sum+a[u].num,tmp1+1,tmp2,tmp3);
	if(tmp2!=n/2) dfs(u+1,sum+b[u].num,tmp1,tmp2+1,tmp3);
	if(tmp3!=n/2) dfs(u+1,sum+c[u].num,tmp1,tmp2,tmp3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(tong,0,sizeof(tong));
		ans=0;
		flag1=flag2=0;
		cnt1=cnt2=cnt3=1;
		tot[1]=tot[2]=tot[3]=0;
		n=read();
		for(int i=1;i<=n;++i){
			cin>>a[i].num>>b[i].num>>c[i].num;
			if(b[i].num!=0) flag1=1;
			if(c[i].num!=0) flag2=1;
			a[i].bo=1,b[i].bo=2,c[i].bo=3;
			a[i].ren=b[i].ren=c[i].ren=i;
		}		
		if(n<=30){
			maxx=0;
			dfs(1,0,0,0,0);
			cout<<maxx<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		if(flag1==0 && flag2==0){
//			cout<<"ok"<<endl;
			for(int i=1;i<=n/2;++i){
				ans+=a[i].num;
			}
			cout<<ans<<endl;
			continue;
		}
	}
		
	return 0;
}
/*
Ren5Jie4Di4Ling5%

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
1 0 0
1 0 0
2 0 0
2 0 0
2
10 9 8
4 0 0

*/
