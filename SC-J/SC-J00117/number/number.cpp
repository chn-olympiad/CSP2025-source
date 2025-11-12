#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
char a[100010];
int b[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long c=0;
	for(int i=1;;i++){
		scanf("%c",&a[i]);
		if(a[i]=='\n'||a[i]==' '){
			break;
		} 
		c++;
	}
	long long d=0; 
	for(int i=1;i<=c;i++){
		if(a[i]<='9'&&a[i]>='0'){
			d++;
			b[d]=int(a[i]);
		}
	}
	sort(b+1,b+c+1,cmp);
	for(int i=1;i<=d;i++){
		long long m=char(b[i]);
		printf("%c",m);
	}
	return 0;
}