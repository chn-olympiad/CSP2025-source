#include<bits/stdc++.h>
using namespace std;
long long t,n,b[10],s,c[10][1000000];
struct sct{
	long long a;
	long long b;
}a[1000000][10];
bool cmp(sct a,sct b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	while(t--)
	{
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j].a;
			a[i][j].b=j; 
		}
		for(int i=1;i<=n;i++)
		sort(a[i]+1,a[i]+3+1,cmp);
		for(int i=1;i<=n;i++)
		s+=a[i][1].a;
		/*or(int i=1;i<=n;i++)
		if(a[i][1].b==1) b[1]++,c[1][++x]=a[i][1].a;
		else if(a[i][2].b==1) b[2]++,c[2][++y]=a[i][2].a;
		else if(a[i][3].b==1) b[3]++,c[3][++z]=a[i][3].a;
		sort(c[1]+1,c[1]+x+1);
		sort(c[2]+1,c[2]+y+1);
		if(b[1]>n/2)
		{
			s-=c[1][x];
			for(int i=1;i<=n;i++)
			if(a[i][1].a==c[1][x])
			{
				s+=a[i][2].a;
				break;
			}
		}
		if(b[2]>n/2)
		{
			s-=c[2][x];
			for(int i=1;i<=n;i++)
			if(a[i][2].a==c[2][x])
			{
				s+=a[i][3].a;
				break;
			}
		}*/
		cout<<s<<endl;
	}
	return 0;
}
