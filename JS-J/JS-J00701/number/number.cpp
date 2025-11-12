#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000001];
bool flag=true;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size(),j=0;
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}sort(a,a+j);
	for(int i=0;i<j;i++){
		if(a[i]!=0){
			flag=false;
		}
	}if(flag){
		cout<<0;
		return 0;
	}else{
		for(int i=j-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
