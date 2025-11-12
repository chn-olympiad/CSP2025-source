#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[s[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		while(m[i]){
			m[i]--;
			cout<<i;
		}
	} 
	return 0;
} 
