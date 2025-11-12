#include<bits/stdc++.h>
#define MAXN 100005
#define int long long

using namespace std;
namespace FastIO
{
	inline string _rs()
	{
		string str="";
		int ch=getchar();
		while(ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
		while(ch!=' ' && ch!='\n' && ch!='\r' && ch!=EOF){
			str.push_back(ch);
			ch=getchar();
		}
		return str;
	}
	inline void _ws(string a,char b)
	{
		int len=a.size();
		for(int i=0;i<len;i++) putchar(a[i]);
		putchar(b);
		return ;
	}
	inline int _r()
	{
		int flag=1,ans=0,ch=getchar();
		while((ch<'0' || ch>'9') && ch!=EOF){
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0' && ch<='9'){
			ans=(ans<<1)+(ans<<3)+(ch^48);
			ch=getchar();
		}
		return flag*ans;
	}
	inline void _w(int a,char b)
	{
		if(a<0) a=-a,putchar('-');
		int sta[22],top=0;
		do{
			sta[top++]=a%10;
			a/=10;
		}while(a);
		while(top) putchar(sta[--top]+48);
		putchar(b);
		return ;
	}
}
using namespace FastIO;

int T,n,a[MAXN][5],maxP[MAXN],max1P[MAXN],cnt[5],dif[MAXN],cntDif,YCP,ans;

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T=_r();
	while(T--){
		n=_r();
		cntDif=0;
		YCP=-1;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(dif,0,sizeof(dif));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) a[i][j]=_r();
			int maxx=-1;
			for(int j=1;j<=3;j++) if(a[i][j]>maxx) maxx=a[i][j],maxP[i]=j;
			maxx=-1;
			for(int j=1;j<=3;j++) if(a[i][j]>maxx && j!=maxP[i]) maxx=a[i][j],max1P[i]=j;
			cnt[maxP[i]]++;
			ans+=a[i][maxP[i]];
			if(cnt[maxP[i]]*2>n) YCP=maxP[i];
		}
		if(YCP==-1){
			_w(ans,'\n');
			continue;
		}
		
		for(int i=1;i<=n;i++) if(maxP[i]==YCP) dif[++cntDif]=a[i][maxP[i]]-a[i][max1P[i]];
		sort(dif+1,dif+1+cntDif);
		int cs=cnt[YCP]-(n/2);
		for(int i=1;i<=cs;i++) ans-=dif[i];
		_w(ans,'\n');
	}
	
	return 0;
}
