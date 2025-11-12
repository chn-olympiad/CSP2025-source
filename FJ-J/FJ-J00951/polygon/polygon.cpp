#include<bits/stdc++.h>
using namespace std;
int n,a[5005],boo=0;
long long sum=0,ans=0,mod=998244353;
void dfs(int num)
{
	for(int i=1;i<=n-num;i++)
	ans++; 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		boo=1;
	}	
	sort(a+1,a+n+1);
	if(boo==0)
	{
		dfs(n);
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	for(int j=i+1;j<=n-1;j++)
	for(int l=j+1;l<=n;l++)
	{
		sum=a[i]+a[j]+a[l];
		if(sum>2*a[l])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}		
	}
	if(n>3)
	for(int i=1;i<=n-3;i++)
	for(int j=i+1;j<=n-2;j++)
	for(int l=j+1;l<=n-1;l++)
	for(int k=l+1;k<=n;k++)
	{
		sum=a[i]+a[j]+a[l]+a[k];
		if(sum>2*a[k])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=5)
	for(int i=1;i<=n-4;i++)
	for(int j=i+1;j<=n-3;j++)
	for(int l=j+1;l<=n-2;l++)
	for(int k=l+1;k<=n-1;k++)
	for(int y=k+1;y<=n;y++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[k];
		if(sum>2*a[y])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=6)
	for(int i=1;i<=n-5;i++)
	for(int j=i+1;j<=n-4;j++)
	for(int l=j+1;l<=n-3;l++)
	for(int k=l+1;k<=n-2;k++)
	for(int y=k+1;y<=n-1;y++)
	for(int p=y+1;p<=n;p++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[p]+a[k];
		if(sum>2*a[p])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=7)
	for(int i=1;i<=n-6;i++)
	for(int j=i+1;j<=n-5;j++)
	for(int l=j+1;l<=n-4;l++)
	for(int k=l+1;k<=n-3;k++)
	for(int y=k+1;y<=n-2;y++)
	for(int p=y+1;p<=n-1;p++)
	for(int h=p+1;h<=n;h++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h];
		if(sum>2*a[h])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=8)
	for(int i=1;i<=n-7;i++)
	for(int j=i+1;j<=n-6;j++)
	for(int l=j+1;l<=n-5;l++)
	for(int k=l+1;k<=n-4;k++)
	for(int y=k+1;y<=n-3;y++)
	for(int p=y+1;p<=n-2;p++)
	for(int h=p+1;h<=n-1;h++)
	for(int num1=h+1;num1<=n;num1++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1];
		if(sum>2*a[num1])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=9)
	for(int i=1;i<=n-8;i++)
	for(int j=i+1;j<=n-7;j++)
	for(int l=j+1;l<=n-6;l++)
	for(int k=l+1;k<=n-5;k++)
	for(int y=k+1;y<=n-4;y++)
	for(int p=y+1;p<=n-3;p++)
	for(int h=p+1;h<=n-2;h++)
	for(int num1=h+1;num1<=n-1;num1++)
	for(int num2=num1+1;num2<=n;num2++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2];
		if(sum>2*a[num2])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=10)
	for(int i=1;i<=n-9;i++)
	for(int j=i+1;j<=n-8;j++)
	for(int l=j+1;l<=n-7;l++)
	for(int k=l+1;k<=n-6;k++)
	for(int y=k+1;y<=n-5;y++)
	for(int p=y+1;p<=n-4;p++)
	for(int h=p+1;h<=n-3;h++)
	for(int num1=h+1;num1<=n-2;num1++)
	for(int num2=num1+1;num2<=n-1;num2++)
	for(int num3=num2+1;num3<=n;num3++)
	{
		sum=a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num3])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=11)
	for(int i=1;i<=n-10;i++)
	for(int j=i+1;j<=n-9;j++)
	for(int l=j+1;l<=n-8;l++)
	for(int k=l+1;k<=n-7;k++)
	for(int y=k+1;y<=n-6;y++)
	for(int p=y+1;p<=n-5;p++)
	for(int h=p+1;h<=n-4;h++)
	for(int num1=h+1;num1<=n-3;num1++)
	for(int num2=num1+1;num2<=n-2;num2++)
	for(int num3=num2+1;num3<=n-1;num3++)
	for(int num4=num3+1;num4<=n;num4++)
	{
		sum=a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num4])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=12)
	for(int i=1;i<=n-11;i++)
	for(int j=i+1;j<=n-10;j++)
	for(int l=j+1;l<=n-9;l++)
	for(int k=l+1;k<=n-8;k++)
	for(int y=k+1;y<=n-7;y++)
	for(int p=y+1;p<=n-6;p++)
	for(int h=p+1;h<=n-5;h++)
	for(int num1=h+1;num1<=n-4;num1++)
	for(int num2=num1+1;num2<=n-3;num2++)
	for(int num3=num2+1;num3<=n-2;num3++)
	for(int num4=num3+1;num4<=n-1;num4++)
	for(int num5=num4+1;num5<=n;num5++)
	{
		sum=a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num5])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=13)
	for(int i=1;i<=n-12;i++)
	for(int j=i+1;j<=n-11;j++)
	for(int l=j+1;l<=n-10;l++)
	for(int k=l+1;k<=n-9;k++)
	for(int y=k+1;y<=n-8;y++)
	for(int p=y+1;p<=n-7;p++)
	for(int h=p+1;h<=n-6;h++)
	for(int num1=h+1;num1<=n-5;num1++)
	for(int num2=num1+1;num2<=n-4;num2++)
	for(int num3=num2+1;num3<=n-3;num3++)
	for(int num4=num3+1;num4<=n-2;num4++)
	for(int num5=num4+1;num5<=n-1;num5++)
	for(int num6=num5+1;num6<=n;num6++)
	{
		sum=a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num6])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=14)
	for(int i=1;i<=n-13;i++)
	for(int j=i+1;j<=n-12;j++)
	for(int l=j+1;l<=n-11;l++)
	for(int k=l+1;k<=n-10;k++)
	for(int y=k+1;y<=n-9;y++)
	for(int p=y+1;p<=n-8;p++)
	for(int h=p+1;h<=n-7;h++)
	for(int num1=h+1;num1<=n-6;num1++)
	for(int num2=num1+1;num2<=n-5;num2++)
	for(int num3=num2+1;num3<=n-4;num3++)
	for(int num4=num3+1;num4<=n-3;num4++)
	for(int num5=num4+1;num5<=n-2;num5++)
	for(int num6=num5+1;num6<=n-1;num6++)
	for(int num7=num6+1;num7<=n;num7++)
	{
		sum=a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num7])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=15)
	for(int i=1;i<=n-14;i++)
	for(int j=i+1;j<=n-13;j++)
	for(int l=j+1;l<=n-12;l++)
	for(int k=l+1;k<=n-11;k++)
	for(int y=k+1;y<=n-10;y++)
	for(int p=y+1;p<=n-9;p++)
	for(int h=p+1;h<=n-8;h++)
	for(int num1=h+1;num1<=n-7;num1++)
	for(int num2=num1+1;num2<=n-6;num2++)
	for(int num3=num2+1;num3<=n-5;num3++)
	for(int num4=num3+1;num4<=n-4;num4++)
	for(int num5=num4+1;num5<=n-3;num5++)
	for(int num6=num5+1;num6<=n-2;num6++)
	for(int num7=num6+1;num7<=n-1;num7++)
	for(int num8=num7+1;num8<=n;num8++)
	{
		sum=a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num8])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=16)
	for(int i=1;i<=n-15;i++)
	for(int j=i+1;j<=n-14;j++)
	for(int l=j+1;l<=n-13;l++)
	for(int k=l+1;k<=n-12;k++)
	for(int y=k+1;y<=n-11;y++)
	for(int p=y+1;p<=n-10;p++)
	for(int h=p+1;h<=n-9;h++)
	for(int num1=h+1;num1<=n-8;num1++)
	for(int num2=num1+1;num2<=n-7;num2++)
	for(int num3=num2+1;num3<=n-6;num3++)
	for(int num4=num3+1;num4<=n-5;num4++)
	for(int num5=num4+1;num5<=n-4;num5++)
	for(int num6=num5+1;num6<=n-3;num6++)
	for(int num7=num6+1;num7<=n-2;num7++)
	for(int num8=num7+1;num8<=n-1;num8++)
	for(int num9=num8+1;num9<=n;num9++)
	{
		sum=a[num9]+a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num9])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=17)
	for(int i=1;i<=n-16;i++)
	for(int j=i+1;j<=n-15;j++)
	for(int l=j+1;l<=n-14;l++)
	for(int k=l+1;k<=n-13;k++)
	for(int y=k+1;y<=n-12;y++)
	for(int p=y+1;p<=n-11;p++)
	for(int h=p+1;h<=n-10;h++)
	for(int num1=h+1;num1<=n-9;num1++)
	for(int num2=num1+1;num2<=n-8;num2++)
	for(int num3=num2+1;num3<=n-7;num3++)
	for(int num4=num3+1;num4<=n-6;num4++)
	for(int num5=num4+1;num5<=n-5;num5++)
	for(int num6=num5+1;num6<=n-4;num6++)
	for(int num7=num6+1;num7<=n-3;num7++)
	for(int num8=num7+1;num8<=n-2;num8++)
	for(int num9=num8+1;num9<=n-1;num9++)
	for(int num10=num9+1;num10<=n;num10++)
	{
		sum=a[num10]+a[num9]+a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num10])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=18)
	for(int i=1;i<=n-17;i++)
	for(int j=i+1;j<=n-16;j++)
	for(int l=j+1;l<=n-15;l++)
	for(int k=l+1;k<=n-14;k++)
	for(int y=k+1;y<=n-13;y++)
	for(int p=y+1;p<=n-12;p++)
	for(int h=p+1;h<=n-11;h++)
	for(int num1=h+1;num1<=n-10;num1++)
	for(int num2=num1+1;num2<=n-9;num2++)
	for(int num3=num2+1;num3<=n-8;num3++)
	for(int num4=num3+1;num4<=n-7;num4++)
	for(int num5=num4+1;num5<=n-6;num5++)
	for(int num6=num5+1;num6<=n-5;num6++)
	for(int num7=num6+1;num7<=n-4;num7++)
	for(int num8=num7+1;num8<=n-3;num8++)
	for(int num9=num8+1;num9<=n-2;num9++)
	for(int num10=num9+1;num10<=n-1;num10++)
	for(int num11=num10+1;num11<=n;num11++)
	{
		sum=a[num11]+a[num10]+a[num9]+a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num11])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=19)
	for(int i=1;i<=n-18;i++)
	for(int j=i+1;j<=n-17;j++)
	for(int l=j+1;l<=n-16;l++)
	for(int k=l+1;k<=n-15;k++)
	for(int y=k+1;y<=n-14;y++)
	for(int p=y+1;p<=n-13;p++)
	for(int h=p+1;h<=n-12;h++)
	for(int num1=h+1;num1<=n-11;num1++)
	for(int num2=num1+1;num2<=n-10;num2++)
	for(int num3=num2+1;num3<=n-9;num3++)
	for(int num4=num3+1;num4<=n-8;num4++)
	for(int num5=num4+1;num5<=n-7;num5++)
	for(int num6=num5+1;num6<=n-6;num6++)
	for(int num7=num6+1;num7<=n-5;num7++)
	for(int num8=num7+1;num8<=n-4;num8++)
	for(int num9=num8+1;num9<=n-3;num9++)
	for(int num10=num9+1;num10<=n-2;num10++)
	for(int num11=num10+1;num11<=n-1;num11++)
	for(int num12=num11+1;num12<=n;num12++)
	{
		sum=a[num12]+a[num11]+a[num10]+a[num9]+a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num12])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	if(n>=20)
	for(int i=1;i<=n-19;i++)
	for(int j=i+1;j<=n-18;j++)
	for(int l=j+1;l<=n-17;l++)
	for(int k=l+1;k<=n-16;k++)
	for(int y=k+1;y<=n-15;y++)
	for(int p=y+1;p<=n-14;p++)
	for(int h=p+1;h<=n-13;h++)
	for(int num1=h+1;num1<=n-12;num1++)
	for(int num2=num1+1;num2<=n-11;num2++)
	for(int num3=num2+1;num3<=n-10;num3++)
	for(int num4=num3+1;num4<=n-9;num4++)
	for(int num5=num4+1;num5<=n-8;num5++)
	for(int num6=num5+1;num6<=n-7;num6++)
	for(int num7=num6+1;num7<=n-6;num7++)
	for(int num8=num7+1;num8<=n-5;num8++)
	for(int num9=num8+1;num9<=n-4;num9++)
	for(int num10=num9+1;num10<=n-3;num10++)
	for(int num11=num10+1;num11<=n-2;num11++)
	for(int num12=num11+1;num12<=n-1;num12++)
	for(int num13=num12+1;num13<=n;num13++)
	{
		sum=a[num13]+a[num12]+a[num11]+a[num10]+a[num9]+a[num8]+a[num7]+a[num6]+a[num5]+a[num4]+a[i]+a[j]+a[l]+a[y]+a[p]+a[k]+a[h]+a[num1]+a[num2]+a[num3];
		if(sum>2*a[num13])
		{
			ans++;
			if(ans>=mod)
			ans-=mod;
		}	
	}
	ans=ans%mod;
	cout<<ans<<endl;
	return 0;
 }

