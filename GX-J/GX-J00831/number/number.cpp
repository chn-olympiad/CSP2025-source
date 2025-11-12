#include<bits/stdc++.h>
using namespace std;
int x[1000010],b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.length();
	for(int i=0;i<a;i++){
		if(s[i]>='0' and s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	long long max=0;
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			if(b[i]!=0){
				max=max*10+i;
			}
		}
	}
	cout<<max;
	return 0;
}
