#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long sum=0,k;
struct ab{
	long long a,b,c;
	long long aa,bb,cc;
	long long k;
}a[100001];
long long num[4];
bool kpi(ab p,ab q){
	return p.aa<q.aa;
}
bool kpj(ab p,ab q){
	return p.bb<q.bb;
}
bool kpz(ab p,ab q){
	return p.cc<q.cc;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(num,0,sizeof(num));
		sum=0; 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			k=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].aa=min(abs(a[i].a-a[i].b),abs(a[i].a-a[i].c));
			a[i].bb=min(abs(a[i].a-a[i].b),abs(a[i].b-a[i].c));
			a[i].cc=min(abs(a[i].c-a[i].a),abs(a[i].b-a[i].c));
			//cout<<a[i].aa<<" "<<a[i].bb<<" "<<a[i].cc<<endl;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c) k=1;
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) k=2;
			else k=3;
			num[k]++;
			a[i].k=k;
			sum+=max(a[i].a,max(a[i].b,a[i].c));
		}
		int flag=0;
		for(int i=1;i<=3;i++)
		{
			if(num[i]>n/2) {
				flag=i;
				break;
			}
		}
		if(flag==0) cout<<sum<<endl;
		else if(flag==1){
			sort(a+1,a+1+n,kpi);
			int i=1;
			while(num[1]>n/2){
				if(a[i].k==1)
				{
					sum-=a[i].aa;
					num[1]--;
				}
				i++;
			}
			cout<<sum<<endl;
		}
		else if(flag==2){
			sort(a+1,a+1+n,kpj);
			int i=1;
			while(num[2]>n/2){
				if(a[i].k==2)
				{
					sum-=a[i].bb;
					num[2]--;
				}
				i++;
			}
			cout<<sum<<endl;
		}
		else if(flag==3){
			sort(a+1,a+1+n,kpz);
			int i=1;
			while(num[3]>n/2){
				if(a[i].k==3)
				{
					sum-=a[i].cc;
					num[3]--;
				}
				i++;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
 } 
