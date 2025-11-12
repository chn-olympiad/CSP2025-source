#include<bits/stdc++.h>
using namespace std;
long long a[1000005],k;
int cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}		
	}sort(a+1,a+1+k,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}for(long long i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
} 
