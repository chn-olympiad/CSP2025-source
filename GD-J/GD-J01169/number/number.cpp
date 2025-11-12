#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+1;
string s;
int a[MAX];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 
