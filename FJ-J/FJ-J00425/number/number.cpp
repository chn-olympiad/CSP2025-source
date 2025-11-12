#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0;
	cin>>s;
	for(int i=0;i<=100000;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=(int)s[i]-'0';
			
		}
	}
	sort(a+1,a+1+t);
	if(a[t]==0){
		cout<<0;
		return 0;
	}
	for(int i=t;i>=1;i--)cout<<a[i]; 
	return 0;
} 
