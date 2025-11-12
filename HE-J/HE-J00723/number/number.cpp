#include<iostream>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	string c;
	int a=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		c[a]=s[i];
		a++;
		if(a>0 && c[a]>c[a-1]){
			int b;
			b=c[a-1];
			c[a-1]=c[a];
			c[a]=b;
		}
	}
	cout<<c;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
