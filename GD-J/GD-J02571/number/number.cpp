#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int s2[1000000];
int z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int a=0;
	while(z<1000000){
		if(s[z]>='0'&&s[z]<='9'){
		   s2[a]=s[z]-'0';
		   	 a++;
		}
		z++;
	}
	sort(s2,s2+a);
		for(int j=a-1;j>=0;j--){
		    cout<<s2[j];
		}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
