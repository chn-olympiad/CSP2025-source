#include<iostream>
using namespace std;
int num[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0'&&s[i]<='9')
			num[s[i]-'0']++;
	bool flag=true;
	for (int i=1;i<=9;i++)
		if (num[i]!=0)
			flag=false;
	if (flag){
		printf("0");
		return 0;
	}
	for (int i=9;i>=0;i--)
		while(num[i]--)
			printf("%d",i);
	return 0;
}
