#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000005],sum=0;
bool cmp(int c,int b){
	return c>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}

	return 0;
} 
