#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin >>s;
	int n=s.size(); 
	for(int i=0;i<n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<=j;i++){
		cout <<a[i];
	}
	return 0;
}
