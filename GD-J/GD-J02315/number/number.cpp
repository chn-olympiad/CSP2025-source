#include<bits/stdc++.h>
using namespace std;
string a;
int len,shu[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++){
		if('0'<=a[i] && a[i]<='9'){
			shu[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(shu[i]){
			cout<<i;
			shu[i]--;
		}
	}
	return 0;
} 
