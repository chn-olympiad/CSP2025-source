#include <bits/stdc++.h>
using namespace std;

const int MAXn = 1e6+5;
string s;
int len;
int a[MAXn],idx=0;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len = s.size();
	for (int i=0;i<len;i++){
		if (s[i] >= '0' && s[i] <= '9')
			a[idx++] = s[i] - '0';
	}
	
	sort(a,a+idx,cmp);
	for (int i=0;i<idx;i++)
		cout<<a[i];
	
	
	
	
	return 0;
} 
