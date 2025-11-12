#include<bits/stdc++.h>
using namespace std;
const int Max = 1e6+1;
char ch;
char arr[Max];
int top;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while((ch=getchar())!=EOF && ch!='\n'){
		if('0'<=ch && ch<='9'){
			arr[top++] = ch;
		}
	}
	sort(arr,arr+top,greater<char>());
	for(int i=0;i<top;++i){
		putchar(arr[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
