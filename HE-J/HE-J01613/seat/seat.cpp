#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

long long n,m,r2;
long long a[116],b[116];
set<long long> s;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	long long k=m*n;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		//s.insert(a[i]);
	}
	long long r=a[1];
	//cout<<r<<endl;
	
	sort(a+1,a+k+1);
	//for(int i=0;i<s.size();i++)
	//{
	//	b[i+1]=s.front;//现在是成绩由高到低排列 
	//	s.pop();
	//}
	for(int i=1,j=k;i<=k;i++,j--)
	    b[i]=a[j];
	
	long long r2=1;
	for(int i=1;i<k;i++)
	{
		if(b[i]==r)
		{
			r2=i;
			//r=-1;
			//cout<<r2<<" "<<b[i]<<endl;
			break;
		}
	}
	
	//cout<<r2<<endl;
	
	bool ss=true;
	long long nn=1,mm=1;
	for(int i=1;i<r2;i++)
	{
		if(ss)
		{
			if(nn!=n)
			    nn++;
			else
			{
				mm++;
				ss=false;
				continue;
			}
		}
		else
		{
			if(nn!=1)
			    nn--;
			else
			{
				mm++;
				ss=true;
				continue;
			}
		}
	}
	cout<<mm<<" "<<nn;
	return 0;
}
