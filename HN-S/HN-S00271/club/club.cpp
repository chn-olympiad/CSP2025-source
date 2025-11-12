#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
struct T{
	int a1;
	int a2;
	int a3;
}n[MAXN];

int t,a1,a2,a3,temp;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>temp;
		for(int i=0;i<temp;i++){
		cin>>n[i].a1>>n[i].a2>>n[i].a3;
		if(n[i].a1>n[i].a2)
		{
			if(n[i].a1>n[i].a3)
			a1+=n[i].a1;
			else
			a3+=n[i].a3;
		}
		else
		{
			if(n[i].a2>n[i].a3)
			a2+=n[i].a2;
			else
			a3+=n[i].a3;
		}
		}
		cout<<a1+a2+a3<<endl;
	
	
	
		
	}
}
