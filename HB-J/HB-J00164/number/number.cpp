#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num[20]={0};
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
