#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5*1e5+5;
int n,k,x,q,p,m,y;
bool l;
string a[N];
ll b[N];
ll er[21];
int c[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	er[0]=1;
	for(int i=1;i<=20;i++) er[i]=er[i-1]*2;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		m=0;
		cin>>b[i];
		y=b[i];
		if(l&&b[i]==1) continue;
        else l=false;
		if(k==0){
			if(b[i]==0) p++;
			continue;
		}
		while(b[i]>0){
			a[i][m]=char(b[i]%2);
			b[i]/=2;
			m++;
		}
		c[i]=max(c[i-1],m);
		if(i==1)
		{
			b[i]=y;
			continue;
		}
		for(int j=0;j<c[i];j++){
			if(a[i][j]==a[i-1][j]) a[i][j]='0';
			else
			{
				a[i][j]='1';
				b[i]+=er[j];
			}
		}
	}
	if(l){
		if(k>1) cout<<0;
		else if(k==1) cout<<n<<endl;
		else cout<<n/2<<endl;
		return 0;
	}
	if(k==0)
	{
		cout<<p;
		return 0;
	}
	x=1,p=0;
	for(int i=1;i<=n;i++){
		for(int j=x;j<=i;j++)
		    if(b[i]-b[j]==k)
			{
				q++;
				x=i;
			}
		p=max(p,q);
	}
	cout<<p<<endl;
	return 0;
}