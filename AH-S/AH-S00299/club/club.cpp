#include<bits/stdc++.h>
using namespace std;
long long lb1,lb2,lb3,ans,n;
struct manyi
{
	long long a;
	long long b;
	long long c;
};
bool amp(manyi x,manyi y)
{
	return max(x.b,x.c)>max(y.b,y.c);
}
bool bmp(manyi x,manyi y)
{
	return max(x.a,x.c)>max(y.a,y.c);
}
bool cmp(manyi x,manyi y)
{
	return max(x.a,x.b)>max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		lb1=0,lb2=0,lb3=0,ans=0;
		cin>>n;
		manyi yi[100005],er[100005],san[100005];
		int a,b,c;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			if(a==max(a,max(b,c))){
				yi[lb1+1].a=a;
				yi[lb1+1].b=b-a;
				yi[lb1+1].c=c-a;
				lb1++;
				ans+=a;
			}
			else if(b==max(a,max(b,c))){
				er[lb2+1].a=a-b;
				er[lb2+1].b=b;
				er[lb2+1].c=c-b;
				lb2++;
				ans+=b;
			}
			else if(c==max(a,max(b,c))){
				san[lb3+1].a=a-c;
				san[lb3+1].b=b-c;
				san[lb3+1].c=c;
				lb3++;
				ans+=c;
			}
		}
		if(lb1>n/2)
		{
			sort(yi+1,yi+lb1+1,amp);
			for(int i=1;i<=lb1-n/2;i++)
			ans+=max(yi[i].b,yi[i].c);
		}
		else if(lb2>n/2)
		{
			sort(er+1,er+lb2+1,bmp);
			for(int i=1;i<=lb2-n/2;i++)
			ans+=max(er[i].a,er[i].c);
		}
		else if(lb3>n/2)
		{
			sort(san+1,san+lb3+1,cmp);
			for(int i=1;i<=lb3-n/2;i++)
			ans+=max(san[i].b,san[i].a);
		}
		cout<<ans<<endl;
	}
	return 0;
}
