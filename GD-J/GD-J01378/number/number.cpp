#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long a[N],ai=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){//遍历字符串S 
		for(int j=0;j<=9;j++){//是否存在1-9的数字 
			if(s[i]==j+48){
				a[ai]=j;
				ai++;
			}
		}
	}
	sort(a,a+ai,greater<int>());
	for(int i=0;i<ai;i++){
		cout<<a[i];
	}
	return 0;
}
