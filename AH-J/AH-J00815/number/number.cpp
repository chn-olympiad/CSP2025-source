#include<bits/stdc++.h>
using namespace std;
char s;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int as=0;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			a[as]=s-'0';
			as++;
		}
	}
	sort(a,a+as,cmp);
	for(int i=0;i<as;i++){
		cout<<a[i];
	}
	
	return 0;
}
