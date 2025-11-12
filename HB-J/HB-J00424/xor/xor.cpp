#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int n,k,ans = 0,xoor;
int a[N];
int fflag = 0;
int flag[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i =1 ; i<= n; i++)
	{
		cin>>a[i];
	}
	xoor = a[1];
	if(k == 0)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i] == 0)ans++;
			/*for(int i = 1; i<=n;i++)
			{
				for(int j = 1;j<=i;j++)
				{
					if(a[i] == a[j] and i != j)
					{
						ans++;
						continue;
					}
				}
			}	*/
		}
		
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i] == k){
				ans++;
				//cout<<i<<"="<<k<<" "<<endl;
				flag[i] = 1;
			}
			
		}
		for(int i = 1; i<=n;i++)
			{
				
				for(int j = 2;j<=n;j++)
				{
					
					xoor = a[i];
					for(int te = i;te<=j;te++){
						xoor = xoor ^ a[te];
						//cout <<"xor:"<< te <<"  "<<xoor<<" ^ "<< a[te]<<" " <<(xoor ^ a[te])<<endl;
					}
					//cout << i <<" "<<j<<"  "<<xoor<<" "<<a[i]<<" "<<a[j]<<endl;
					for(int op = i;op<=j;op++)
					{
						if(flag[op]!=0)
							fflag = 0;
					}
					if(xoor == k and fflag == 1)
					{
						ans++;
						//cout <<"xoor:"<<xoor<<" "<<"!"<<"  "<<i<<" "<<j<<endl<<endl;
						i = j+1;
					}
				}
			}
	}
	cout << ans;


}
