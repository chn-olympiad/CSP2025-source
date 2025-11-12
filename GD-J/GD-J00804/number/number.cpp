//1-number
#include<bits/stdc++.h>
using namespace std;
int a[1000060];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c){
		if(c>='0'&&c<='9')
			a[++a[0]]=c-'0';
	}
	sort(a+1,a+1+a[0]);
	for(int i=a[0];i>=1;i--)
		cout<<a[i];
	return 0;
}
