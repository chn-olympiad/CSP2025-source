#include<bits/stdc++.h>
using namespace std;
string s,b;
long long n=0,len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	if(len==1&&s[0]>='0'&&s[0]<='9'){
		cout<<s;
		return 0;
	}
	if(len==2){
		if(s[0]>='0'&&s[0]<='9'&&s[1]>='0'&&s[1]<='9'){
			if(s[0]>s[1]){
				cout<<s[0]<<s[1];
				return 0;
			}
			else{
				cout<<s[1]<<s[0];
				return 0;
			}
		}else if(s[0]>='0'&&s[0]<='9'){
			cout<<s[0];
			return 0;
		}else if(s[1]>='0'&&s[1]<='9'){
			cout<<s[1];
			return 0;
		}
	}
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[n++]=s[i];
		}else{
			continue;
		}
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<i;j++){
			if(b[i]>b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(long long i=0;i<n;i++){
		cout<<b[i];
	}
	return 0;
}
