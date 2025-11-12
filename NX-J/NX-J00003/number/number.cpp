#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a[100000];
	int b;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i;i<=len(s);i++){
		if(s[i]>=9||s[i]>=0){
			s[i]=a[i]
		}
		if(a[i]>=a[i-1]){
			b=a[i-1];
			a[i-1]=a[i];
			a[i]=b;
		}else{
			cout<<a[i];
			}
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}
