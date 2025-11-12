#include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s=s+'$';
	int n[1000001]={},t[1000001]={};
	int a=0,i=0;
	while(s[a]!='$'){
		if(int(s[a])<=9){
			n[i]=int(s[a]);
			i++;
		}
		a++;
	}
	for (int j=0;j<=i;j++){
		int m=9;
		for (int z=j;z<=i;z++){
			m=min(m,n[z]);
		}
		t[j]=m;
	}
	for (int j=i;j>=0;j--){
		cout<<t[j]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 