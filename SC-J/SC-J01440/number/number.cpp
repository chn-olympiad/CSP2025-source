#include<bits/stdc++.h>
using namespace std;

char s[1000000];
int nums[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i = 0;i<sizeof(s);i++)
		if (s[i]<58 && s[i]>47) nums[s[i]-48]+=1;
	for (int i = 9;i>=0;i--)
		for (int j = nums[i];j>0;j--)
			cout<<i;
	return 0;
}