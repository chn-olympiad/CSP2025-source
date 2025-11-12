#include<bits/stdc++.h>
using namespace std;
int a[1000100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&'9'>=s[i]){
			j++;
			a[j]=s[i]-'0';
		}
	}
	int ans=0;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
} 
