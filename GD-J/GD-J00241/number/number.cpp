#include <bits/stdc++.h>
using namespace std;
int a[1000007];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=1;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[sum]=int(s[i]-'0');
			sum++;
		}
	}
	sum--;
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
