#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000010],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+1+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
