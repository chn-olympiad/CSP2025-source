#include<bits/stdc++.h> 
using namespace std;
int t,n,a[100005][3],ans,ga,gb,gc,cj[200010][2],p,q;
void f(int c,int d){
	if(p)
	{	cj[1][1]=c;
	cj[1][2]=d;}
	else{int w=p/2;
	for(int i=p/4;i>=1;i/=2)
	{
		if(a[c][d]<a[cj[i][1]][cj[i][2]]) w+=i;
		else w-=i;
	}
	if(a[c][d]<a[cj[w+1][1]][cj[w+1][2]])
	w++;
	if(a[c][d]>a[cj[w-1][1]][cj[w-1][2]])
	w--;

	for(int i=p+1;i>=w;i--)
	{
		cj[i][1]=cj[i-1][1];
		cj[i][2]=cj[i-1][2];
	}
		cj[w][1]=c;
	cj[w][2]=d;
	}
	}	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{cin>>a[i][1];
		cin>>a[i][2];
		cin>>a[i][3];
		if(a[i][1]>a[i][2])
		{
			if(a[i][1]>a[i][3])
			{
				ans+=a[i][1];
				a[i][2]-=a[i][1];
				a[i][3]-=a[i][1];
				ga++;
				f(i,2);
				p++;
				f(i,3);
				p++;
				
			}
			else
			{	ans+=a[i][3];
				a[i][2]-=a[i][3];
				a[i][1]-=a[i][3];
				gc++;
			}
		}
		else
		{
			if(a[i][2]>a[i][3])
			{
				ans+=a[i][2];
				a[i][1]-=a[i][2];
				a[i][3]-=a[i][2];
				gb++;
				
			}
			else
			{	ans+=a[i][3];
				a[i][2]-=a[i][3];
				a[i][1]-=a[i][3];
				gc++;
		}
		}}
		while(ga>n/2)
		{q++;
		ans+=a[cj[q][1]][cj[q][2]];
		ga--;	
		}
	cout<<ans<<"\n";
	}
	return 0;
}
