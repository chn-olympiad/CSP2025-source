#include<bits/stdc++.h>
using namespace std;
char a[1000006];
int n;
void init(){
	cin>>a+1;
	n=strlen(a+1);
	return;
}
int b[1000006],m;
void work(){
	m=0;
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++m]=a[i]-'0';
		}
	}
	sort(b+1,b+1+m);
	for(int i=m;i>=1;i--)
		printf("%d",b[i]);
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
