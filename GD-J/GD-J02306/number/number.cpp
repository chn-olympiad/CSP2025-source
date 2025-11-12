#include<bits/stdc++.h>
using namespace std;
string s;
long long temp=0;
bool cmp(int a,int b){
	return a<b;
}
int main(){
//	clog<<'5'-'0';
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[s.size()]={0};
	for(long long i = 0;i<s.size();i++){
		if((s[i]<='9')&&(s[i]>='0')){
			a[temp]=s[i]-'0';
			clog<<s[i]-'0'<<endl;
			temp++;
		}
	}
	sort(a,a+(temp),cmp);
	for(long long i = temp-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
