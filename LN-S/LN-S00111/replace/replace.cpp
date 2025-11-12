#include<bits/stdc++.h>
using namespace std;
string ky[200006];
string kt[200006];
struct caa
{
	int cha;
	int aq;
	int ah;
};
int cmp(caa x,caa y)
{
	return x.aq<y.aq;
}
int cmp2(caa x,caa y)
{
	return x.ah<y.ah;
}
int cmp3(caa x,caa y)
{
	return x.cha<y.cha;
}
caa a[200006];
caa b[200006];
int erf(int t,int ans,int lx)
{
	int l=0,r=t,su;
	int m=(l+r)/2;
	while(l<r)
	{
		m=(l+r)/2;
		if(lx==1)
        {
            su=a[m].aq;
        }
        else if(lx==2)
        {
            su=a[m].ah;
        }
        else
        {
            su=a[m].cha;
        }
		if(su>ans)
		{
			r=m;
		}
		else
		{
			l=(l+r+1)/2;
		}
	}
    return l;
}
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n,q,iii=0;
	cin>>n>>q;
	cin>>ky[0]>>kt[0];
	for(int i=0;i<ky[0].size();i++)
	{
		if(ky[0][i]!='a' && ky[0][i]!='b')
		{
			iii=2;
		}
		if(ky[0][i]=='b')
		{
			a[0].aq=i;
			a[0].ah=ky[0].size()-i-1;
			a[0].cha=i;
			iii++;
		}
		if(kt[1][i]=='b')
		{
			a[1].cha=i-a[1].cha;
			break;
		}
	}
	if(iii==1)
	{
		for(int i=1;i<n;i++)
		{
			cin>>ky[i]>>kt[i];
			for(int j=0;j<ky[i].size();j++)
			{
				if(ky[i][j]=='b')
				{
					a[i].aq=j;
					a[i].ah=ky[i].size()-j-1;
					a[i].cha=j;
				}
				if(kt[i][j]=='b')
				{
					a[i].cha=j-a[i].cha;
					break;
				}
			}
		}
		string cy,ct;
		int aq2,ah2,cha2;
		for(int i=1;i<=q;i++)
		{
			for(int j=0;j<n;j++)
			{
				b[j].ah=a[j].ah;
				b[j].aq=a[j].aq;
				b[j].cha=a[j].cha;
			}
			cin>>cy>>ct;
			for(int j=0;j<cy.size();j++)
			{
				if(cy[j]=='b')
				{
					aq2=j;
					ah2=cy.size()-j-1;
					cha2=j;
				}
				if(ct[j]=='b')
				{
					cha2=j-cha2;
					sort(a,a+n,cmp);
					a[n].aq=a[n-1].aq+1;
					int nn=erf(n,aq2,1);
					sort(a,a+nn,cmp2);
					a[nn].ah=a[nn-1].ah+1;
					//cout<<nn<<endl;
					int nnn=erf(nn,ah2,2);
					sort(a,a+nnn,cmp3);
					//cout<<a[0].aq<
					//cout<<nnn<<endl;
					a[nnn].cha=a[nnn-1].cha+1;
					cout<<erf(nnn,cha2,3)-erf(nnn,cha2-1,3)<<endl;

					break;
				}
			}
			for(int j=0;j<n;j++)
			{
				a[j].ah=b[j].ah;
				a[j].aq=b[j].aq;
				a[j].cha=b[j].cha;
			}
		}
		return 0;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			string bc,cb;
			cin>>bc>>cb;
		}
		for(int i=0;i<q;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
