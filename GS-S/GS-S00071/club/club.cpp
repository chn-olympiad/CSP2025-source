#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,club1,club2,club3,num[0];
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>num[i];
		for(int j=1;j<i;j++){
			num[j] += i;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(num[i]>i){
			club1++;
			num[i]+=i;
		}
		else if(num[i]>=i && num[i]>=n)
		{
			club2++;
			num[i]+=n;
		}
		else{
			club3++;
		}
		cout<<num[i+n];
	}
	
	
	return 0;	
}
	



