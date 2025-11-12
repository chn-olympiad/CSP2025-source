#include<bits/stdc++.h>
using namespace std;
char c[1000005]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	short a[1000005];
	cin>>(c+1);
	int l1=strlen(c+1);
	int l=1;
	for(int i=1;i<=l1;i++){
		if('0'<=c[i]&&c[i]<='9'){
			a[l]=c[i]-'0';
			l++;
		}
	}
	l--;
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

