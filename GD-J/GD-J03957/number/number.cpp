#include<bits/stdc++.h>
using namespace std;
const int K=10e6+10;
char str[K];
int sz[K];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int szn=1;
	long long size=strlen(str);
	for(long long i=0;i<size;i++){
		if(str[i]>='0'&&str[i]<='9'){
			sz[szn]=str[i]-'0';
			szn++;
		}
	}
	
	sort(sz+1,sz+szn,cmp);
	for(int i=1;i<szn;i++){
		cout<<sz[i];
	}
	return 0;
}
