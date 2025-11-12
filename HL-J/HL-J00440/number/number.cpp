#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
using namespace std;
int b[10]={0};
int main(){
	char a[1000001];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	int s;
	scanf("%c",&a);
	s=strlen(a);
	for(int i=1;i<=s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]]++;
		}}
	for(int j=9;j>=1;j++){
		if(b[j]!=0){
			for(int i=1;i<=b[j];i++){
				cout<<b[j];
	}
	}}

	return 0;
}
