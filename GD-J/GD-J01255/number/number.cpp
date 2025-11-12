#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	²âÊÔ:freopen("number1.in","w",stdout);
// ²»ÒªÐ´³Éfreopen("number.ans","w",stdout); 
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
