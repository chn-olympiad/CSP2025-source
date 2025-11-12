#include<bits/stdc++.h>
using namespace std;
char s;
vector<int> a(12,0);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s-'0'>=0&&s-'0'<=9){
			a[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
} 