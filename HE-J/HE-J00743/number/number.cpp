#include<bits/stdc++.h>
using namespace std;
char num[1000],k;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[k]=a[i];
			k++;
		}
	}
	sort(num,num+k);
	for(int i=k-1;i>=0;i--){
		printf("%c",num[i]);
	}
	return 0;
} 
