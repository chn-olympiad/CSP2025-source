#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int s[1000010],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int m=strlen(a);
	for(int i=0;i<m;i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			s[++k]=a[i]-'0';
		}
	}
	sort(s+1,s+1+k);
	for(int i=k;i>=1;i--){
		cout<<s[i];
	}
}  