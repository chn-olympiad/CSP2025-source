#include<bits/stdc++.h>
using namespace std;
int n,m,a[10]={0};
char s[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = strlen(s);
	for(int i = 0;i < n;i++){
		m=s[i];
		if(47<m && m<58){
			a[m-48]++;
		}
		//47<s<58
	}
	
	int b=0;
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			b*=10;
			b+=i;
		}
	}
	cout<<b;
	return 0;
}
