#include<bits/stdc++.h>
using namespace std;

string s;
int a[20];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int p=(s[i]-'0');
			a[p]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
	
	return 0;
}
