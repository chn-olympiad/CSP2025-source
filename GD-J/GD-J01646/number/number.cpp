#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],top=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto c:s){
		if(c>='0'&&c<='9'){
			a[top++]=c-'0';
		}
	}
	sort(a+1,a+top,cmp);
	for(int i=1;i<top;++i){
		printf("%d",a[i]);
	}
	return 0;
} 
