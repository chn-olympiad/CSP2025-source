#include <iostream>
using namespace std;

string a;
int s[11];//统计数量

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			s[a[i]-'0']++;
		}
	} 
	for(int i=9;i>=0;i--){
		for(int j=1;j<=s[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
