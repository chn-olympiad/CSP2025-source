#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long a[1000000]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	long long sum=0,num=0;
	long long n=0;
	getline(cin,str);
	for(long long i=0;i<str.size();i++){
		if(str[i]>='1'&&str[i]<='9')		
		a[i]=str[i]-'0';
		sum++;
		if(str[i]=='0')
		n++;
	}
	sort(a,a+sum,cmp);
	int ans=0;
	for(long long i=0;i<sum;i++){
		if(a[i]!=0)
		cout<<a[i];
		ans++;
	}
	for(long long i=1;i<=n;i++){
		cout<<"0";
	}
	return 0;
}
