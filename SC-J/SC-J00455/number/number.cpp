#include<bits/stdc++.h>
using namespace std;

/*
使用桶标记
遍历一遍+输出
时间复杂度：O(n)
n<=1e6
*/

int num[20];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])) num[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		if(num[i]>0){
			while(num[i]--) printf("%d",i);
		}
	}
	return 0;
}