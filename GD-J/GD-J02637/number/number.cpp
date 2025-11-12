#include<bits/stdc++.h>
using namespace std;
long long a[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool f=0;
	for(int i=9;i>=1;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++) printf("%d",i);
			f=1;
		}
	}
	if(f){
		for(int i=1;i<=a[0];i++){
			printf("0");
		}
	}else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
