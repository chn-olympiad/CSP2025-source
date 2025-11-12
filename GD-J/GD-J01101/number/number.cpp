#include<bits/stdc++.h>
using namespace std; 
char a[1000005],b[1000005];
int cnt;
bool hzm(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++cnt]=a[i];
		}
	}
	sort(b+1,b+1+cnt,hzm);
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
}
