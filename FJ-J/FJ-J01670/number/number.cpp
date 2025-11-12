#include<bits/stdc++.h>
using namespace std;
char s,a=0,b;
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<s;i++){
		if(1<=s && s<=9){
			if(s>a){
				a=s;
			}
		}
		cout<<a;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
