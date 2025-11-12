#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
			
		
		if(s[0]<s[1])
			swap(s[0],s[1]);
		if(s[0]<s[2])
			swap(s[0],s[2]);
		if(s[0]<s[3])
			swap(s[0],s[3]);
		if(s[0]<s[4])
			swap(s[0],s[4]);
		if(s[0]<s[5])
			swap(s[0],s[5]);
		if(s[0]<s[6])
			swap(s[0],s[6]);
		if(s[0]<s[7])
			swap(s[0],s[7]);
		if(s[1]<s[2])
			swap(s[2],s[1]);
		if(s[1]<s[3])
			swap(s[1],s[3]);
		if(s[1]<s[4])
			swap(s[1],s[4]);
		if(s[1]<s[5])
			swap(s[1],s[5]);
		if(s[1]<s[6])
			swap(s[1],s[6]);
		if(s[1]<s[7])
			swap(s[1],s[7]);	
		if(s[2]<s[3])
			swap(s[2],s[3]);
		if(s[2]<s[4])
			swap(s[2],s[4]);
		if(s[2]<s[5])
			swap(s[2],s[5]);
		if(s[2]<s[6])
			swap(s[2],s[6]);
		if(s[2]<s[7])
			swap(s[2],s[7]);
		if(s[3]<s[4])
			swap(s[3],s[4]);
		if(s[3]<s[5])
			swap(s[3],s[5]);
		if(s[3]<s[6])
			swap(s[3],s[6]);
		if(s[3]<s[7])
			swap(s[3],s[7]);
		if(s[4]<s[5])
			swap(s[4],s[5]);
		if(s[4]<s[6])
			swap(s[4],s[6]);
		if(s[4]<s[7])
			swap(s[4],s[7]);
		if(s[5]<s[6])
			swap(s[5],s[6]);
		if(s[5]<s[7])
			swap(s[5],s[7]);
		if(s[6]<s[7])
			swap(s[6],s[7]);
		
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
