#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001];
	int n,a;
	cin>>s;
	for(int j=1;j<=n;j++){
		for(int i=n;i>=j;i--){
			if(s[i]<s[i-1]){
				i--;
			}
			if(s[i]>s[i-1]){
				s[i]=a;
				s[i]=s[i-1];
				s[i-1]=a;
			}
		}
		for(int k=1;k<=n;k++){
			cout<<s[k];
		}
	}
	fclose(stdin)
	fclose(stdout)
	return 0;
}
