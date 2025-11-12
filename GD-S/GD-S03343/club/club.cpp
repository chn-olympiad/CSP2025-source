#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> a;
struct ma1{
	long long ma01;
	int ma02;
};
long long  n;
void club01(long long  k)
{
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)a.push_back(0);
		long long temp=0;
		for(int i=1;i<=n;i++)
		{
			ma1 ma;
			long long a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a[0]<=n/2){
				ma.ma01=a1,ma.ma02=0;
				if(a2>ma.ma01&&a[1]<n/2)ma.ma01=a2,ma.ma02=1;
				if(a3>ma.ma01&&a[2]<n/2)ma.ma01=a3,ma.ma02=2;
			}
			else if(a[1]<=n/2){
				ma.ma01=a2,ma.ma02=1;
				if(a3>ma.ma01&&a[2]<n/2)ma.ma01=a3,ma.ma02=2;
		 }
			else	ma.ma01=a3,ma.ma02=2;
			a[ma.ma02]+=1;
			temp+=ma.ma01;
		}
		cout<<temp;
		a.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
