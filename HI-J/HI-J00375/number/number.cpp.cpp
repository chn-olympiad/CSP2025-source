#include<bits/stdc++.h>
using namespace std;
string s;
int sum=0,a[1000001];
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	
	
	cin >> s;
	int line=s.size();
	for(int i=0;i<line;i++){
		if(s[i]>='0'&& s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
			
		}
	}
	sort(a+1,a+1+sum);
	if(a[sum]==0&&a[sum-1]==0){
		cout<<0;
	}
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}




