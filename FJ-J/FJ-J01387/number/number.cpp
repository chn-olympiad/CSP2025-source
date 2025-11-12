#include<bits/stdc++.h> 
using namespace std;
string a;
char n[1000005];
long long s[114514],b,ab=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(long long i=0;i<1000005;i++){
		if(n[i]<='9'&&n[i]>='0'){
			s[i]=n[i]-'0'; 
			ab++;
		}
	}
	sort(s,s+ab);
	for(long long i=ab;i>=0;i--){
		if(s[i]!=0){
			cout<<s[i];
			b++;
		}
	}
	for(long long i=0;i<ab-b;i++){
		cout<<"0";
	}
	return 0;
}
