#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int x[1000000];
int k=0;
int main(){
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]<=57&&s[i]>=48){
			x[k]=s[i];
			k++;
		}
	}
	sort(x,x+k);

	for(int i=0;i<k;i++){
		
		cout<<((int)x[k-i-1]-48);
	}
	
	return 0;
}