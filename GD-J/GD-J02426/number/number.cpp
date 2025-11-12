#include<bits/stdc++.h>
using namespace std;
char ch;
int a[1000006],o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ch=getchar();
	while(ch!='\n'){
		if(ch>='0'&&ch<='9') {
			a[++o]=ch-'0';
		}
		ch=getchar();
	}
	sort(a+1,a+1+o);
	for(int i=o;i>0;i--) cout<<a[i];
	cout<<endl;
	return 0;
}
