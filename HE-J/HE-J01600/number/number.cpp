#include<bits/stdc++.h>
using namespace std;
string s;
int sum = 0;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 1;i <= s.size();i++){
		for(int i = 1;i <= s.size();i++){
			if(s[i] > s[i+1] && s[i] > sum && s[i] > ){
				sum = s[i];
			}
		}
		cout<<sum;
	}
	return 0;
}
