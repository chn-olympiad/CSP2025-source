#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[j]=(s[i]-=48);
			j++;
		}
	}
	sort(num,num+1);
	cout<<num;
	return 0;
} 
