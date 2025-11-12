#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5;
long long n,m;
long long a[N]; 
bool pan(int a,int b)
{
	if(a==1&&b==0) return 1;
if(a==0&&b==1) return 1;
return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i]; 
	 }
	 
		if(n==2)
		{
			if(pan(a[0],a[1]))
			{
				cout<<"2";
				return 0;
			}
			else{
				cout<<"1";
				return 0;
			}
		}
		if(n==1) {
			if(a[1]==0)
			{
				cout<<"1";
				return 0;
			}
			
		}

	return 0;
}
