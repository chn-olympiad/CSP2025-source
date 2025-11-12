#include<bits/stdc++.h>
using namespace std;

int num[5001];
int bsb[5001];
long long sum=0;
int n;

void dg(int nm[5001],int mx,int s)
{
    if(s>=n)
    {
        return;
    }

    int m=mx;
    if(num[s]>mx)
    {
        m=num[s];
    }
    if( (nm[s-1]+num[s]>m*2) && (s>=2) )
    {
        sum++;
    }

    nm[s]=nm[s-1];
    dg(nm,mx,s+1);

    nm[s]+=num[s];
    dg(nm,m,s+1);

    return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    dg(bsb,0,0);

    cout<<sum;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
