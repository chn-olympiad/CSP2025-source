#include<iostream>
#include<algorithm>
using namespace std;
string s;int num[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	int sum=0;
	for (int i=9;i>=1;i--){
		for (int j=1;j<=num[i];j++){
			sum++;
			cout <<i;
		}
	}
	if (sum==0){
		cout<<0;
	}else{
		for (int i=1;i<=num[0];i++)cout <<0;
	}
	return 0;
}
