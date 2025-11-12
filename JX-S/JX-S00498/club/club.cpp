#include<iostream>
using namespace std;

struct stu
{
	int n;
	int myd[50];
};

int main(){
	int t;
	stu n,myd[50];
	cin>>t;
	for(int i = 0;i < t;i ++)
	{
		cin>>n;
		for(int j = 0;j < n;j ++)
		{
			cin>>myd[j];
		}
	}
	freopen("club.in","r",stdin);
	
	freopen("club.out","w",stdin);
	return 0;
}
