#include <bits/stdc++.h>
using namespace std;

string s;
int n,m=0;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57){
			a[m]=int(s[i])-48;
			m++;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	
	return 0;
}
