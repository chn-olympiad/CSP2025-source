#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char str[1000005],c;
	int top=0;
	while(cin>>c){
		if(c>='0'&&c<='9')str[top++]=c;
	}
	sort(str,str+top);
	for(int i=top-1;i>=0;--i){
		cout<<str[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
