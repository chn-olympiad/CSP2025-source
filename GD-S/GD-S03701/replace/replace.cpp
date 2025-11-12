#include<bits/stdc++.h>
using namespace std;
int n,q;
string x,y;
struct th{
	string f,t;
}a[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].f>>a[i].t;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int lx=x.size(),ly=y.size();
		if(lx!=ly)
		{
			cout<<0<<endl;
			continue;
		}
		int s=0;
		for(int i=0;i<lx;i++)
			for(int j=i;j<lx;j++)
			{
				string xy=x.substr(i,j-i+1),yy=y.substr(i,j-i+1),xx=x.substr(0,i),yx=y.substr(0,i),yz=y.substr(j+1,lx-j),xz=x.substr(j+1,lx-j);
				if(xx!=yx||xz!=yz)
					continue;
				for(int k=1;k<=n;k++)
					if(xy==a[k].f&&yy==a[k].t)
						s++;
			}
		cout<<s<<endl;
	}
	return 0;
}
