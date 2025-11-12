#include <iostream>
#include <algorithm>
using namespace std;
string s,t;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++){
		if(s[i]>='0'&&s[i]<='9')	a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
