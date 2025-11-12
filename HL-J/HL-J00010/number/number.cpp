#include<bits/stdc++.h>
using namespace std;
int a[1000110];
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long num=0;
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=57){
			j++;
			a[j]=s[i];
			num++;
		}
	}
	sort(a+1,a+num+1,greater<int>());
	for(int i=1;i<=num;i++){
		cout<<a[i]-48;
	}
	return 0;
}
