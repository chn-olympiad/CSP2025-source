#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10*10*10*10*10*10+5]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	getline(cin,s);
	int length=s.size();
	for(int i=0;i<length;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j+1);
	for(;j>=2;j--){
		cout<<a[j];
	}
	return 0;
}
