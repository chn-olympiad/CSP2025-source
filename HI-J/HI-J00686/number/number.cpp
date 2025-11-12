#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
string s;
int num=0,a[1000001]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num++;
			a[num]=s[i]-'0';
		} 
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++) cout<<a[i];
	return 0;
}

