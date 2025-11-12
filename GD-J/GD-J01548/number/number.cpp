#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10],sum=0;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=int(s[i]-'0');
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
