#include<bits/stdc++.h>
using namespace std;
long long a,s[1000],e;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
    	cin>>s[i];
	}
	sort(s,s+a);
	if(a==3)
	{
		if(s[0]+s[1]>s[2])e++;
		cout<<e;
		return 0;
	}
	if(a==4)
	{
		if(s[0]+s[1]>s[2])e++;
		if(s[0]+s[1]>s[3])e++;
		if(s[1]+s[2]>s[3])e++;
		if(s[0]+s[1]+s[2]+s[3]>s[3]*2)e++;
		cout<<e;
		return 0;
	}
	if(a==5)
	{
		if(s[0]+s[1]>s[2])e++;
		if(s[0]+s[1]>s[3])e++;
		if(s[0]+s[1]>s[4])e++;
		if(s[0]+s[2]>s[3])e++;
		if(s[0]+s[2]>s[4])e++;
		if(s[0]+s[3]>s[4])e++;
		if(s[1]+s[2]>s[3])e++;
		if(s[1]+s[2]>s[4])e++;
		if(s[1]+s[3]>s[4])e++;
		if(s[2]+s[3]>s[4])e++;
		if(s[0]+s[1]+s[2]+s[3]>s[3]*2)e++;
		if(s[0]+s[1]+s[2]+s[4]>s[4]*2)e++;
		if(s[0]+s[1]+s[3]+s[4]>s[4]*2)e++; 
		if(s[0]+s[2]+s[3]+s[4]>s[4]*2)e++;
		if(s[1]+s[2]+s[3]+s[4]>s[4]*2)e++;
		if(s[0]+s[1]+s[2]+s[3]+s[4]>s[4]*2)e++;
		cout<<e;
		return 0;
	}
	if(a==6)
	{
		if(s[0]+s[1]>s[2])e++;
		if(s[0]+s[1]>s[3])e++;
		if(s[0]+s[1]>s[4])e++;
		if(s[0]+s[1]>s[5])e++;
		if(s[0]+s[1]>s[6])e++;
		if(s[0]+s[2]>s[3])e++;
		if(s[0]+s[2]>s[4])e++;
		if(s[0]+s[2]>s[5])e++;
		if(s[0]+s[3]>s[4])e++;
		if(s[0]+s[3]>s[5])e++;
		if(s[0]+s[4]>s[5])e++;
		if(s[1]+s[2]>s[3])e++;
		if(s[1]+s[2]>s[4])e++;
		if(s[1]+s[2]>s[5])e++;
		if(s[1]+s[3]>s[4])e++;
		if(s[2]+s[3]>s[5])e++;
		if(s[2]+s[4]>s[5])e++;
		if(s[3]+s[4]>s[5])e++;
		if(s[0]+s[1]+s[2]+s[3]>s[3]*2)e++;
		if(s[0]+s[1]+s[2]+s[4]>s[4]*2)e++;
		if(s[0]+s[1]+s[2]+s[5]>s[5]*2)e++;
		if(s[0]+s[1]+s[3]+s[4]>s[4]*2)e++; 
		if(s[0]+s[2]+s[3]+s[5]>s[5]*2)e++;
		if(s[1]+s[2]+s[3]+s[4]>s[4]*2)e++;
		if(s[1]+s[2]+s[3]+s[5]>s[5]*2)e++;
		if(s[1]+s[2]+s[4]+s[5]>s[5]*2)e++;
		if(s[1]+s[3]+s[4]+s[5]>s[5]*2)e++;
		if(s[2]+s[3]+s[4]+s[5]>s[5]*2)e++;
		if(s[0]+s[1]+s[2]+s[3]+s[4]>s[4]*2)e++;
		if(s[0]+s[1]+s[2]+s[3]+s[5]>s[5]*2)e++;
		if(s[0]+s[1]+s[2]+s[4]+s[5]>s[5]*2)e++;
		if(s[0]+s[1]+s[3]+s[4]+s[5]>s[5]*2)e++;
		if(s[0]+s[2]+s[3]+s[4]+s[5]>s[5]*2)e++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]>s[5]*2)e++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[6]*2)e++;
		cout<<e;
		return 0;
	}
	cout<<0;

	return 0;
}

