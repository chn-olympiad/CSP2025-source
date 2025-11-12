#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s[1000000];
	char a[1000000],ans=1,x;
	for(int i=1;i<=ans;i++){
		cin>>s;
	}
	for(int i=0;i<strlen(s);i++){
		if(strlen(s)==1){
			cout<<s;
		}
		else if(s[i]>='a' and s[i]<='z'){
			x=0;
		}
		else {
			for(int i=0;i<strlen(s);i++){
				a[i]=s[i];
			}
			}
		}
	

	for(int i=0;i<strlen(s);i++){
		for(int j=0;j<strlen(s);j++){
			if(a[j+1]>a[j]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<strlen(s);i++){
		cout<<a[i];
	}
	
	
	
	
	return 0;
} 
