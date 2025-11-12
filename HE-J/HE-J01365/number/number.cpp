#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int a=0,c=0;
	cin>>n;
	a=n.size();
	char b[a+1];
	for(int i=0;i<=a;i++){
		if(n[i]>='0'&&n[i]<='9'){
			c++;
			b[c]=n[i];
			
		}
	}
	sort(b,b+1+c);
	for(int i=c;i>=1;i--){
		printf("%d",b[i]-'0');
	}
	return 0;
}
