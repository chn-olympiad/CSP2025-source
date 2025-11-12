#include<bits/stdc++.h>
using namespace std;

string s;int z,a[15];bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	z=s.size();
	for(int i=0;i<z;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout << i;
		}
	}
	return 0;
}
