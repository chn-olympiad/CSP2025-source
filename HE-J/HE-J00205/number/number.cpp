#include<bits/stdc++.h>
using namespace std;
string a;
int ans;
int wyz;
string xc;
int s[1008611];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			s[ans]=a[i]-'0';
			ans++;
		}
	}
	sort(s,s+ans,greater<int>());
	if(ans<18)
	{
		for(int i=0;i<ans;i++)
		{
			wyz=wyz*10+s[i];
		}
		cout<<wyz;
		return 0;
	}
	for(int i=0;i<ans;i++)
	{
		xc+=(s[i]+'0');
	}
	cout<<xc;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
