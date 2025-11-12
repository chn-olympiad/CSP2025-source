#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
string s,s1;
int a[N],b[N],mi=INT_MAX,sum=0,ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	for(int i=0;i<=s.size();i++){
		if(s1[i]<s1[i+1]){
			swap(s1[i],s1[i+1]);
		}
	}
	for(int i=0;i<=s.size();i++){
		cout<<s[i];
	}
	return 0;
}
