#include "bits/stdc++.h" 
using namespace std;
const int N=5*1e5+10;
int n,k;
int tp1=1,tp2=1,s1,s0;
int c,last;
int a[N],s[N];
bool f[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//异或 ^
	//A:a[i]=1
	//B:0<=a[i]<=1 <=> a[i]==1||a[i]==0
	//C:a[i]<=255
	int i,j;
	cin>>n>>k;
	s[0]=0;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
		
		if(a[i]!=1) tp1=0;
		if(!(a[i]==1||a[i]==0)) tp2=0;
		if(a[i]==1) s1++; if(a[i]==0) s0++;
		
		s[i]=s[i-1]^a[i];//0^n=n
	}
	
	if(tp1)//A
	{
		if(!(k==1||k==0)) cout<<0;
		else if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		return 0;
	}
	
	if(tp2)//B
	{
		if(!(k==1||k==0)) cout<<0;
		else if(k==1) cout<<s1;
		else if(k==0) 
		{
			for(i=1;i<n;i++)
			{
				if(a[i]==1&&a[i+1]==1&&f[i]==false&&f[i+1]==false) 
				{
					c++; f[i]=true;f[i+1]=true;
				}
			}
			cout<<c+s0;
		}
		return 0;
	}
	for(i=1;i<=n;i++)//贪心 只能对前4个样例 
	{
		if((s[i]^s[last])==k)
		{
			//cout<<c+1<<"  "<<last<<" "<<s[last]<<"  "<<i<<" "<<s[i]<<endl; 
			last=i;
			c++;	
		}
	}
	s[n+1]=0;
	int first=n+1,w=0;
	for(i=n;i>=1;i--)
	{
		if((s[i]^s[first])==k)
		{
			
			first=i;
			w++;	
		}
	}
	cout<<max(c,w);
	return 0;
	fclose(stdin);
	fclose(stdout);
	
	
	
}
