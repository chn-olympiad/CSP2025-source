#include<iostream>
#include<vector>
#include<windows.h>

using namespace std;

long long n,k,cnt; 
int a[500005];
bool b[500005];
void solve()
{
	cout<<cnt;
	exit(0);
}
int isok(int i,int j)
{
	for(;j>=i;j--){
		if(b[j]==1)return j;//返回最后一个不符合的位置 
	}
	return 0;
}
int main()//想出|正解 
{
//	a^=b;
// x^y后再^x=y,^y=x,应该符合贪心思想，滑动窗口试试
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1]; 
	}  
	for(int i=1;i<=n;i++)//窗口大小
	{	
		int l=1,r=i;
		//预处理部分，如果找不到就跳了吧 
		int c=isok(l,r); 
		while(c)
		{
			l=c+1;
			r=l+i-1;
			if(r>n)
			{	
				solve();	
			}
			c=isok(l,r);
		}
		//主程序部分 
		for(;r<=n;l++,r++)
		{	
			if(b[r]==1)//判断新入队的是否为已经符合条件的，若为则向前寻找至不为的,如果当前长度已经找不到了就跳了吧 
			{	
				l=r+1;
				r=l+i-1;
				int check=isok(l,r); 
				while(check)
				{
					l=check+1;
					r=l+i-1;
					if(r>n)
					{
						solve();	
					}
					check=isok(l,r);
				}
			}
			int now=a[r];now^=a[l-1];
			if(now==k)//判断cnt++并标记为符合条件的 
			{
				cnt++;
				for(int x=l;x<=r;x++)
				{
					b[x]=1;
				}
				//标记完以后大迁徙，向前寻找不为的，如果找不到就跳了吧 
				l=r+1;
				r=l+i-1;
				int check=isok(l,r); 
				while(check)
				{
					l=check+1;
					r=l+i-1;
					if(r>n)
					{
						solve();	
					}
					check=isok(l,r);
				}
				l--,r--;
			}
		}
	}
	return 0;
}
