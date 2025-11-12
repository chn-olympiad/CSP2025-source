#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin>>s;
	long long a[5*10000+3]={};
	int n=s.size();
	int y=0;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a+0,a+j);
	long long sum=0,u=0;
	for(int i=0;i<j;i++){
	
		
		sum+=pow(10,u)*a[i];
		cout<<a[i]<<endl;
		u+=1;
	}

	cout<<sum;
	return 0;
}
