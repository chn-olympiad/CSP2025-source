#include <bits/stdc++.h>
using namespace std;
char s[1010];
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=1000;i++){
		s[i]=123;
	}
	cin>>s;
	int m=0;
	while(s[m]>=48&&s[m]<=122){
		m++;
	}
	if(m==1&&s[0]>='0'&&s[0]<='9'){
		cout<<s;
		return 0;
	}
	int j=0;
	for(int i=0;i<m;i++){
		if(s[i]>=48&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	if(j==1){
		cout<<a[j];
		return 0;
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}

	return 0;
}

