#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int a[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			cnt++;
		}
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){
			a[i]=s[i]-'0';
		}
	}
	sort(a+0,a+1010,cmp);
	for(int i=0;i<=1010;i++){
		if(a[i]==0){
			continue;
		}else{
			cout<<a[i];
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<0;
	}
	return 0;
}
