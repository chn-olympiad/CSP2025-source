#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxn=INT_MIN,cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>maxn*2)cout<<1;
		else cout<<0;
		exit(0);
	}
	if(n==4)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cnt++;
		if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2)cnt++;
		if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2)cnt++;
		cout<<cnt;
		exit(0);
	}
	if(n==5)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cnt++;
		if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2)cnt++;
		if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2)cnt++;
		if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2)cnt++;
		if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2)cnt++;
		if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2)cnt++;
		if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2)cnt++;
		if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2)cnt++;
		if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2)cnt++;
		if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[5]>max(a[1],max(a[2],max(a[3],a[5])))*2)cnt++;
		if(a[1]+a[2]+a[4]+a[5]>max(a[1],max(a[2],max(a[4],a[5])))*2)cnt++;
		if(a[1]+a[3]+a[4]+a[5]>max(a[1],max(a[3],max(a[4],a[5])))*2)cnt++;
		if(a[2]+a[3]+a[4]+a[5]>max(a[2],max(a[3],max(a[4],a[5])))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>maxn*2)cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==6)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cnt++;
		if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2)cnt++;
		if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2)cnt++;
		if(a[1]+a[2]+a[6]>max(a[1],max(a[2],a[6]))*2)cnt++;
		if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2)cnt++;
		if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2)cnt++;
		if(a[1]+a[3]+a[6]>max(a[1],max(a[3],a[6]))*2)cnt++;
		if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2)cnt++;
		if(a[1]+a[4]+a[6]>max(a[1],max(a[4],a[6]))*2)cnt++;
		if(a[1]+a[5]+a[5]>max(a[1],max(a[5],a[6]))*2)cnt++;
		if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2)cnt++;
		if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2)cnt++;
		if(a[2]+a[3]+a[6]>max(a[2],max(a[3],a[6]))*2)cnt++;
		if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2)cnt++;
		if(a[2]+a[4]+a[6]>max(a[2],max(a[4],a[6]))*2)cnt++;
		if(a[2]+a[5]+a[6]>max(a[2],max(a[5],a[6]))*2)cnt++;
		if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2)cnt++;
		if(a[3]+a[4]+a[6]>max(a[3],max(a[4],a[6]))*2)cnt++;
		if(a[3]+a[5]+a[6]>max(a[3],max(a[5],a[6]))*2)cnt++;
		if(a[4]+a[5]+a[6]>max(a[4],max(a[5],a[6]))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[5]>max(a[1],max(a[2],max(a[3],a[5])))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[6]>max(a[1],max(a[2],max(a[3],a[6])))*2)cnt++;
		if(a[1]+a[2]+a[4]+a[5]>max(a[1],max(a[2],max(a[4],a[5])))*2)cnt++;
		if(a[1]+a[2]+a[4]+a[6]>max(a[1],max(a[2],max(a[4],a[6])))*2)cnt++;
		if(a[1]+a[3]+a[4]+a[5]>max(a[1],max(a[3],max(a[4],a[5])))*2)cnt++;
		if(a[1]+a[3]+a[4]+a[6]>max(a[1],max(a[3],max(a[4],a[6])))*2)cnt++;
		if(a[1]+a[3]+a[5]+a[6]>max(a[1],max(a[3],max(a[5],a[6])))*2)cnt++;
		if(a[1]+a[4]+a[5]+a[6]>max(a[1],max(a[4],max(a[5],a[6])))*2)cnt++;
		if(a[2]+a[3]+a[4]+a[5]>max(a[2],max(a[3],max(a[4],a[5])))*2)cnt++;
		if(a[2]+a[3]+a[4]+a[6]>max(a[2],max(a[3],max(a[4],a[6])))*2)cnt++;
		if(a[2]+a[3]+a[5]+a[6]>max(a[2],max(a[3],max(a[5],a[6])))*2)cnt++;
		if(a[2]+a[4]+a[5]+a[6]>max(a[2],max(a[4],max(a[5],a[6])))*2)cnt++;
		if(a[3]+a[4]+a[5]+a[6]>max(a[3],max(a[4],max(a[5],a[6])))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>max(a[1],max(a[2],max(a[3],max(a[4],a[6]))))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]>max(a[1],max(a[2],max(a[3],max(a[5],a[6]))))*2)cnt++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]>max(a[1],max(a[2],max(a[4],max(a[5],a[6]))))*2)cnt++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]>max(a[1],max(a[3],max(a[4],max(a[5],a[6]))))*2)cnt++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]>max(a[2],max(a[3],max(a[4],max(a[5],a[6]))))*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))*2)cnt++;
		cout<<cnt;
		exit(0);
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2)
					cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>max(a[i],max(a[j],max(a[k],a[l])))*2)
						cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>max(a[i],max(a[j],max(a[k],max(a[l],a[o]))))*2)
							cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>max(a[i],max(a[j],max(a[k],max(a[l],a[o]))))*2)
							cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],a[p])))))*2)
								cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int awa=p+1;awa<=n;awa++)
									if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[awa]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[p],a[awa]))))))*2)
									cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int awa=p+1;awa<=n;awa++)
									for(int qwq=1;qwq<=n;qwq++)
										if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[awa]+a[qwq]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[p],max(a[awa],a[qwq])))))))*2)
										cnt++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int awa=p+1;awa<=n;awa++)
									for(int qwq=1;qwq<=n;qwq++)
										for(int ultra=1;ultra<=n;ultra++)
											if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[awa]+a[qwq]+a[ultra]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[p],max(a[awa],max(a[qwq],a[ultra]))))))))*2)
											cnt++;
		cout<<cnt;
	}
}
/*
 从某种意义上来说能拿满（
 xiangshangmihuoxingweidashangqwq
 本来是324行的压行才压到168
 fuluoer:mj25-3-1
*/
