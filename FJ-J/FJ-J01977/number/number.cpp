#include<bits/stdc++.h>
using namespace std;
int numbers[1000001];
int qua;
string str;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			numbers[qua++]=str[i]-'0';
		}
	}
	sort(numbers,numbers+qua,cmp);
	for(int i=0;i<qua;i++){
		printf("%d",numbers[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
