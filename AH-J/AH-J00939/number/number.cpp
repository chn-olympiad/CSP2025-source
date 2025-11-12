#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
int cnt[15];
string x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int t=x.size();
	for (int i=0;i<t;i++){
		if (isdigit(x[i])) cnt[x[i]-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}
