#include <bits/stdc++.h>
using namespace std;
long long a[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char t;
	long long i=1,num0=0;
	while(t!='\n'){
		t=cin.get();
		if(t>='1'&&t<='9'){
			a[i]=t-'0';
			i++;
		}
		else if(t=='0'){
			num0++;
		}
	}
	sort(a,a+i);
	i--;
	while(i!=0){
		printf("%d",a[i]);
		i--;
	}
	while(num0!=0){
		printf("0");
		num0--;
	}
	fclose(stdin);
	fclose(stdout);
}