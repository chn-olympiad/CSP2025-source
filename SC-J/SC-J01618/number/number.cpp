#include <bits/stdc++.h>
using namespace std;
string s;
long long r[1000010],k=1;

bool cmp(int a,int b){
	if(a>b)	return true;
	else return false; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			r[k]=s[i]-'0';
			k++; 
		} 
	}
	
	sort(r+1,r+k,cmp);
	if(r[1]==0){
		cout<<0;
	}else{
		for(long long i=1;i<k;i++){
			cout<<r[i];
		}
	}
	return 0;
}