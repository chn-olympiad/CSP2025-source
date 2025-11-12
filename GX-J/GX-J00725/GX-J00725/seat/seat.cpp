#include<bits/stdc++.h>
using namespace std;
int main()
{
   	
   
	int a,b;
	cin>>a>>b;
	vector<int>a1;
	vector<int>b1;
for(int i=0;i<a*b;i++)
{
	i=i;
}
	for(int i=0;i<a*b;i++)
	{
		int y;
		cin>>y;
		a1.push_back(y);
	}
	int w=0;
	sort(a1.begin(),a1.end());
	for(int i=0;i<a*b;i++)
	{
		w=a1[a*b-i-1];
		b1.push_back(w);
	}
	for(int i=0;i<a*b;i++)
	{
		if(a1[0]==b1[i]);
		cout<<"1"<<" "<<i+1;
	}


    return 0;	   
}
