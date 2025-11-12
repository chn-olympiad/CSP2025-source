#include<bits/stdc++.h>
#define int long long
using namespace std;
struct wo{
	int on,tw,th,cha;
}a[100086];
int Max(int x,int y,int z){
	return max(max(x,y),z);
}
int Maxn(int x,int y,int z){
	int l=Max(x,y,z);
	if(l==x) return 1; if(l==y) return 2; if(l==z) return 3;
}
int Min(int x,int y,int z){
	return min(x,min(y,z));
}
int Mid(int x,int y,int z){
	int aaa[4]={0,x,y,z};
	sort(aaa+1,aaa+4);
	return aaa[2];
}
int Midn(int x,int y,int z){
	int l=Mid(x,y,z);
	if(l==x) return 1; if(l==y) return 2; if(l==z) return 3;
}
bool cmp(wo x,wo y){
	if(x.cha!=y.cha) return x.cha>y.cha;
	else return Max(x.on,x.tw,x.th)>Max(y.on,y.tw,y.th);
}
int now[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		now[1]=n/2,now[2]=n/2,now[3]=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].on>>a[i].tw>>a[i].th;
			a[i].cha=Max(a[i].on,a[i].tw,a[i].th)-Mid(a[i].on,a[i].tw,a[i].th);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int ma=Maxn(a[i].on,a[i].tw,a[i].th),mid=Midn(a[i].on,a[i].tw,a[i].th);
			if(now[ma]==0)
				ans+=Mid(a[i].on,a[i].tw,a[i].th),now[mid]--;
			else ans+=Max(a[i].on,a[i].tw,a[i].th),now[ma]--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
