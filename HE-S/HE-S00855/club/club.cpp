#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){int x=0,f=1;char c = getchar();while(c>'9'||c<'0'){if(c == '-')f = -1;c = getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}

int t,n;//找一个桶记录每一各部门内的元素以及id
struct node
{
	int x,y,z,mx,id;
}a[100010];
int su[4],ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n = read();int mxx=-1;
		for(int i = 1;i <= n;i ++)
		{
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if(a[i].x>a[i].y){
				a[i].mx = a[i].x;
				a[i].id = 1;
			}else{
				a[i].mx=a[i].y;
				a[i].id=2;
			}
			if(a[i].mx<a[i].z){
				a[i].mx = a[i].z;
				a[i].id = 3;
			}
		}
		sort(a+1,a+1+n,
		[](node xx,node yy){
			return xx.mx>yy.mx;
		});
		bool f1=true,f2=true;
		for(int i = 1;i <= n;i ++){
			if((a[i].id == 1 || !f2)&&f1)ans+=a[i].x;
			else if((a[i].id == 2||!f1)&&f2)ans+=a[i].y;
			su[a[i].id]++;
			if(su[a[i].id] == n/2){
				if(a[i].id == 1){
					f1=false;
				}else{
					f2=false;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
