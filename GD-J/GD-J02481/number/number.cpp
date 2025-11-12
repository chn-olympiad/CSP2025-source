#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[c++]=s[i]-'0';
		}
	}
	c--;
	sort(a,a+c+1,cmp);
	for(int i=0;i<=c;i++){
		cout<<a[i];
	}
	return 0;
} 
