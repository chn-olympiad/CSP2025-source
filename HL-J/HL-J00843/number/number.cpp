#include<bits/stdc++.h> 
using namespace std;
char s[100001],s2[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			s2[a]=s[i];
			a++;
		}		
	}
	for(int i=0;i<strlen(s2);i++){
			for(int j=1;j<=i;j++){
				if(s2[j]<s2[j+1]){
					swap(s2[j],s2[j+1]);
				}
		}
	}		
		for(int i=0;i<strlen(s2);i++){
		cout<<s2[i];		
	}
	return 0;
}
