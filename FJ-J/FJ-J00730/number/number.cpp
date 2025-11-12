#include<bits/stdc++.h>
using namespace std;
char a[1000001];
char s[1000001];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	while(cin>>s[j]){j++;}
	int n=0;
	for(int i=0;i<j;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
