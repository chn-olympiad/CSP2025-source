#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n[1000001];
	int m[100001];
	cin>>n;
	int len=strlen(n);
	int j=0;
	for(int i=0;i<=len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			m[j]=n[i]-48;
			j++;
		}
	}
	sort(m,m+j);
	for(int i=j-1;i>=0;i--){
		cout<<m[i];
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
