#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	int m=1;
	for(int i=0;i<n;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[m]=s[i]-'0';
			m+=1;
		}
	}
	m-=1;
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
