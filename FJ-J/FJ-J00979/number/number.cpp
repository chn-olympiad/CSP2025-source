#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size()-1;
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	string sum; 
	for(int i=9;i>=0;i--){
		char ss=i+'0';
		while(a[i]--){
			sum+=ss;
		}
	}
	cout<<sum<<endl;
	return 0;
}
