#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int i=0;
	char a[1005];
	for(;;){
		s=getchar();
		if(s>='0' && s<='9'){ a[i]=s;i++;}
		if(s<'0') break;
	}
	for(int j=0;j<i;j++){
		for(int k=0;k<i;k++){
			if(a[j]<a[k]) {
				swap(a[j],a[k]);
			}
		}
	}
	for(int j=i-1;j>=0;j--) cout<<a[j];
	return 0;
}
