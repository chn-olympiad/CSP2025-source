#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int pos=1;
	for(int i = 0;s[i];i++){
		char temp=s[i];
		if('0'<=temp && temp<='9'){
			a[pos]=temp-'0';
			pos++;
		}
	}
	sort(a+1,a+1+pos);
	reverse(a+1,a+1+pos);
	for(int i = 1;i<pos;i++){
		cout<<a[i];
	}
	return 0;
} 
