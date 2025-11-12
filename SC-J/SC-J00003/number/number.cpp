#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	int a[len];
	int k=0;
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
} 