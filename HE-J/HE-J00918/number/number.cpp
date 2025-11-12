#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000];
	int a=strlen(s); 
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	int b[1000000];
	int num=0;
	for(int i=1;i<=a;i++){
		if(s[i]>=0 && s[i]<=9){
			cin>>b[i];
			num++;
		}
	}
	sort(b,b+1);
	int ping=0;
	for(int i=1;i<=num/2;i++){
		ping=s[i];
		s[i]=s[num-i];
		s[num-i]=ping;
	}
	cout<<s;
}
