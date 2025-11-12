#include<bits/stdc++.h>
using namespace std;
const int A=1000005;
string s;
int maxx=-1,m[A],x=0;
long long sum=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[x]=s[i]-'0';
			x++;
		}
	}sort(m+0,m+x,cmp);
	for(int i=0;i<x;i++){
		printf("%d",m[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
