#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	long long x,num;
}mp[N];
bool cmp(node aa,node bb)
{
	return aa.x>bb.x;
}
long long t,n,pos[N],used[N],sec[N],siza,sizb,sizc;
long long ans;
void work()
{
	siza=sizb=sizc=0ll;
	ans=0ll;
	memset(pos,0,sizeof pos);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)scanf("%lld",&mp[j].x),mp[j].num=j;
		sort(mp+1,mp+4,cmp);
		sec[i]=mp[1].x-mp[2].x,pos[i]=mp[1].num;
		ans+=mp[1].x;
		if(mp[1].num==1) siza++;
		else if(mp[1].num==2) sizb++;
		else if(mp[1].num==3) sizc++;
	}
	long long top=0,len=0;
	if(siza>(n/2)) 
	{
		for(int i=1;i<=n;i++) if(pos[i]==1) used[++top]=sec[i];
		len=siza-(n/2);
	}
	else if(sizb>(n/2)) 
	{
		for(int i=1;i<=n;i++) if(pos[i]==2) used[++top]=sec[i];
		len=sizb-(n/2);
	}
	else if(sizc>(n/2)) 
	{
		for(int i=1;i<=n;i++) if(pos[i]==3) used[++top]=sec[i];
		len=sizc-(n/2);
	}
	else {printf("%lld\n",ans);return;}
	sort(used+1,used+top+1);
	for(int i=1;i<=len;i++) ans-=used[i];
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--) work();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//15:09大样例全部通过
//17:30回来写hack 
