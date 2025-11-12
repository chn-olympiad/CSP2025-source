#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],a1=0;
bool t(int x,int y){
	if(x>=y)return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++a1]=s[i]-'0';
		}
	}
	sort(a+1,a+a1+1);
	for(int i=a1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 