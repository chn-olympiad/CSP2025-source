#include<iostream>
using namespace std;
string s;
int box[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0') box[(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		if(box[i]){
			for(int j=1;j<=box[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}

