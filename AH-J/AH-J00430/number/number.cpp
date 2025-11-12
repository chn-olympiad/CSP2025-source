#include<bits/stdc++.h>
using namespace std;
bool pan(char a,char b){
	return (a>b);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[100010]={'0'};
	cin>>s;
	int n=s.length(),j=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='10'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j,pan);
	for(int i=0;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
