#include<bits/stdc++.h>
using namespace std;
char c;
int a[11],b,h;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while((c=getchar())!=10){
		if(c>='0'&&c<='9'){
			b=int(c-'0');
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
