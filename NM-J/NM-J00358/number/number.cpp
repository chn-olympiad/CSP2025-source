#include<bits/stdc++.h>

int b[50]={0};
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x1=0,x=0;
	char a[5000];
	cin>>a;
	while(a[x]){
		if('0'<a[x]<'10'){
			b[x1]=a[x]-'0';
			x1++;
		}
		x++;
	}
	sort(b,b+x1);
	for(int i=x1-1;i>=0;i--){
		cout<<b[i];
	}
}
