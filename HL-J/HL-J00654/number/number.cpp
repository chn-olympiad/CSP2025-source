#include<bits/stdc++.h>
using namespace std;
int num[20];
string s1;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin >> s1;
	for(int i=0;i<s1.size();i++){
		if(isdigit(s1[i])){
			num[s1[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		if(num[j]!=0){
			while(num[j]){
				cout << j;
				num[j]--;
			}
		}
	}
//290es1q0

	return 0;
}