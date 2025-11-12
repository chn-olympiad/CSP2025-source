#include<bits/stdc++.h>
using namespace std;
int b[1000010],p;
char a[1000010];
bool l(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0' && a[i]<='9'){
			p++;
			b[p]=a[i]-'0';
		}
	}
	sort(b+1,b+p+1,l);
	for(int i=1;i<=p;i++){
		cout<<b[i];
	}
	return 0;
}
