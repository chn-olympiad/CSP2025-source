#include <bits/stdc++.h>
using namespace std;
string s;
int q[1000010];
int sum,flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' and s[i]<='9') q[sum]=s[i]-48,sum++;
	}
	sort(q,q+sum);
	while (sum--){
		if (q[sum]==0 && !flag){
			cout<<0;
			return 0;
		} 
		else {
			flag=1;
			cout<<q[sum];
		}
		
	}
	
	return 0;
}
