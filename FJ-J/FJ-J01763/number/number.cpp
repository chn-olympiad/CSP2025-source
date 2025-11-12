#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[10];
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int s=n.size();
	for(int j=0;j<s;j++){
		if(n[j]>='0'&&n[j]<='9'){
			num[n[j]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		while(num[j]--){
			cout<<j;
		}
	}
	return 0;
} 
