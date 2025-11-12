#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;i++){
		if(a[i]<='9'&&a[i]>='0')num[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
} 
