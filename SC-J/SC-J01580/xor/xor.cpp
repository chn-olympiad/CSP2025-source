#include<bits/stdc++.h>
using namespace std;
int a[500006],cnt=0;
int xo(int l,int r)
{
	int sum=0;
	for(int i=l;i<=r;i++)
	{
		sum=sum^a[i];
	}
	return sum;
}
int check(int l,int r,int k,int n,int f)
{
	int x=-1;
	while(x!=k)
	{
	//	cout<<f<<endl;
	//	cout<<l<<" "<<r<<endl;
		if(l<1) l++;
		if(l>n) return 0;
		if(r>n) r--;
		if(r<1) return 0;
		if(l==r)
		{
			if(a[l]==k&&a[r]==k)
			{
		//		cout<<"YES"<<endl;
				cnt++;
			//	cout<<l<<" "<<r<<" "<<k<<endl;
		//		cout<<a[l]<<" "<<a[r]<<endl;
			}
			return 0;
		}
		int last=xo(l,r),left=xo(l+1,r),right=xo(l,r-1);
		int delta=abs(last-k);
		if(delta==0)
		{
		//	cout<<"Yes"<<endl;
			cnt++;
			if(f==1)
			{
				return check(1,l-1,k,n,2)+check(r+1,n,k,n,3);
			}
			else if(f==2)
			{
				return check(1,l-1,k,n,2);
			}
			else if(f==3)
			{
				return check(r+1,n,k,n,3);
			}
		}
		if(abs(left-k)<=delta)
		{
		//	cout<<"zuo"<<endl;
			return check(l+1,r,k,n,f);
		}
		else if(abs(right-k)<=delta)
		{
		//	cout<<"you"<<endl;
			return check(l,r-1,k,n,f);
		}
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum1=0,sum2=0;
	bool f1=0,f2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) sum1++;
		if(a[i]==1) sum2++;
		if(a[i]!=1)
		f1=1;
		if(a[i]!=0&&a[i]!=1)
		f2=1;
	}
	if(f1==0&&f2==0)
	{
		cout<<n/2;
	}
	else if(f1==1&&f2==0)
	{
		if(k==0)
		cout<<sum1;
		if(k==1)
		cout<<sum2;
	}
	else{
	check(1,n,k,n,1);
	cout<<cnt<<endl;
	}
	return 0;
}