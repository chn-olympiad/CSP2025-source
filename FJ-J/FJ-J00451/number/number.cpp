#include<bits/stdc++.h>
using namespace std;
char a[1000000007];
long long s[10000007],d=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	//cout<<strlen(a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[a[i]-'0']++;
		}
	}
	//cout<<"asd";
	for(int i=10;i>0;i--){
		while(s[i]!=0){
			printf("%d",i);
			s[i]--;
		}
	}
	return 0;
}
