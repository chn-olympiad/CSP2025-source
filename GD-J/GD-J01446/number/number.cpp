#include <bits/stdc++.h>
using namespace std;
#define int long long
string str;
int numbers[11];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(isdigit(ch)){
			int num=ch-'0';
			numbers[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(numbers[i]){
			numbers[i]--;
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
