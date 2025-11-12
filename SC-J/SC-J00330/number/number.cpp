#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if('0'<=s[i]&&s[i]<='9')num[s[i]-48]++;
	for(int i=9;i>=0;i--)
		while(num[i]--)printf("%d",i);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}