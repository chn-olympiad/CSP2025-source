#include<bits/stdc++.h> 
using namespace std;
struct peo
{
	int bian;
	int n1,n2,n3;
};
int T,n,m,k,s,k2,k1,k3,king1,king2,king3;
peo a[100010],sw;;
bool flag[100010];
bool cmp1(peo i,peo j)
{
	return i.n1>j.n1;
}
bool cmp2(peo i,peo j)
{
	return i.n2>j.n2;
}
bool cmp3(peo i,peo j)
{
	return i.n3>j.n3;
}
bool cmp4(peo i,peo j)
{
	return i.n2-i.n1>j.n2-j.n1;
}
bool cmp5(peo i,peo j)
{
	return i.n1-i.n2>j.n1-j.n2;
}
peo z1[1000010],z2[1000010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		k1=0;
		k2=0;
		k3=0;
		s=0;
		memset(z1,0,sizeof(z1));
		memset(z2,0,sizeof(z2));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			if(a[i].n2!=0)
			{
				k2=1;
			}
			if(a[i].n3!=0)
			{
				k3=1;
			}
			if(a[i].n1!=0)
			{
				k1=1;
			}
			a[i].bian=i;
		}
		m=n/2;
		if(k1==0)
		{
			if(k3==0)
			{
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=m;i++) 
				{
					s+=a[i].n2;
				}
				cout<<s<<endl;
				continue;
			}
			else
			{
				sort(a+1,a+n+1,cmp3);
				for(int i=1;i<=m;i++) 
				{
					s+=a[i].n3;
				}
				cout<<s<<endl;
				continue;
			}
		}
		if(k2==0&&k3==0)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=m;i++) 
			{
				s+=a[i].n1;
			}
			cout<<s<<endl;
			continue;
		}
		if(k3==0)
		{
			king1=0x3f,king2=0x3f;
			king1=-king1,king2=-king2;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=m;i++)
			{
				s+=a[i].n1;
				s+=a[i+m].n2;
				z1[i]=a[i];
				z2[i]=a[i+m];
			}
			sort(z1+1,z1+m+1,cmp4);
			sort(z2+1,z2+m+1,cmp5);
			for(int i=1;i<=m;i++)
			{
				if(z1[i].n2-z1[i].n1+z2[i].n1-z2[i].n2>0)
				{
					s+=z1[i].n2-z1[i].n1+z2[i].n1-z2[i].n2;
				}
				else
				{
					break;
				}
			}
			cout<<s<<endl;
			continue;
		}
		king1=0x3f,king2=0x3f;
		king1=-king1,king2=-king2;
		
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=m;i++)
		{
			s+=a[i].n1;
			s+=a[i+m].n2;
			z1[i]=a[i];
			z2[i]=a[i+m];
		}
		sort(z1+1,z1+m+1,cmp4);
		sort(z2+1,z2+m+1,cmp5);
		for(int i=1;i<=m;i++)
		{
			if(z1[i].n2-z1[i].n1+z2[i].n1-z2[i].n2>0)
			{
				s+=z1[i].n2-z1[i].n1+z2[i].n1-z2[i].n2;
				sw=z1[i];
				z1[i]=z2[i];
				z2[i]=sw;
			}
			else
			{
				break;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(z1[i].n1<z1[i].n3)
			{
				s+=z1[i].n3-z1[i].n1;
			}
			if(z2[i].n2<z2[i].n3)
			{
				s+=z2[i].n3-z2[i].n2;
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
