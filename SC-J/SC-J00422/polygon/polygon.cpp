#include<bits/stdc++.h>
int search(int n,int length[]);
int c[10000000]
using namespace std;
int main()
{
	freopen("polygon.in.txt","r",stdin);
	freopen("polygon.out.txt","w",stdout);
	int n;
	cin>>n;
	int length[n];
	for(int i=0;i<n;i++) cin>>length[i];
	for(int i=1;i<=n-1;i++) for(int j=0;j<n-i;j++)if(length[j]>length[j+1]) swap(length[j],length[j+i]);
	total=search(1,length);
	cout<<total;
	return 0;
}
int search(int n,int length[])
{
	int time,s=0,a=0,max=-1,b=0;
	for(int j=0;j<n;j++)
	{
		time++;
		while(s>max*2)
		{
			s+=length[a];
			for(int i=0;i<=a-1;i++) if(length[i]>length[i+1]) max=length[i];
			c[time]=1;
		}
		if(!c[time])b++;
		else search(2,length);
	}
}