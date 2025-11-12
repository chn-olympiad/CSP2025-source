#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int len=s.size();
	int idx=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[idx++]=s[i]-'0';
		}
	}
	sort(a,a+idx,cmp);
	for(int i=0;i<idx;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
