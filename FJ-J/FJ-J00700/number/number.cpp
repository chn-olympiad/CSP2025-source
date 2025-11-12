#include<bits/stdc++.h>
using namespace std;
char c;
int stoi(char c){
	return c-'0';
}
bool cmp(int x,int y){
	return x>y;
}
int a[1000001],cnt; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(!isdigit(c)) continue;
		cnt++;
		a[cnt]=stoi(c);
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
