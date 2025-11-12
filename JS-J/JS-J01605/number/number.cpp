#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long int a[N];
	long long int len=1;
	long long int b=s.size()-1;
	for(long long int i=0;i<=b;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[len]=s[i]-'0';
			len++;
		}
	}
	sort(a+1,a+1+len);
	for(long long int i=len;i>1;i--){
		if(a[i]==0 && i==len){
			cout<<"0"<<endl;
			return 0;
		}else{
			cout<<a[i];
		}
	}
    return 0;
}
