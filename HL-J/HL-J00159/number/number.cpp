#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%c",&a);
	int e=0;
	string f=a;
	while(f[0]==0){
		f[e]=0;
		e+=1;
	}
	
	int b[e],d=0;
	for(int i=0;i<e;i++){
		if(a[i]=='5'){
			b[d]=int(a[i]);
			d+=1;
		}
	}
	printf("%d",&d );
	for(int i=1;i<d;i++){
		int c;
		if(b[i]>b[i-1]){
			c=b[i-1];
			b[i-1]=b[i];
			b[i]=c;
			printf("%d",&e);
		}
	}
	printf("%s",&b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

