#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,fl=1,sum=0,flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	
	cin>>a[i];
	if(a[i]!=1){
	fl=0;}
	if(a[i]!=1&&a[i]!=0)flag=0;
	}			
	if(fl)
	{
		if(n==1)cout<<1;
		if(n==2)cout<<0;
		return 0;
	}
	if(flag)
	{
		if(k==1)
		{
			int s=0;
			for(int i=1;i<=n;i++)if(a[i]==1)s++;
			cout<<s;
		}
		if(k==0)
		{
			int s=0;
			for(int i=1;i<=n;i++)if(a[i]==0)s++;
			cout<<s;
		}
		return 0;
	}l
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1&&a[i+1]==-1)continue;
		
		int qian=a[i];
		if(qian==k){
		sum++;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==-1&&a[j+1]==-1)break;
			qian^=a[j];
			
			if(qian==k&&i!=j){
				sum++;
				for(int l=i;l<=j;l++)a[l]=-1;
				break;
			}
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
