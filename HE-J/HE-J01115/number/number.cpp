#include<iostream>
#include<cstdio>
#define var long long
using namespace std;
var a[20];
char v[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>v;
	for(var i=0;v[i]!='\0';i++){
		if('0'<=v[i]&&v[i]<='9'){
			a[v[i]-'0']++;
		}
	}
	for(var i=9;i>=0;i--){
		if(a[i]!=0){
			for(var j=1;j<=a[i];j++) cout<<i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
