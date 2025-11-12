#include<bits/stdc++.h>
using namespace std;
int a[1000010],top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	cin>>c;
	for(int i=0;i<int(c.size());i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[++top]=c[i]-'0';
		}
	}sort(a+1,a+top+1);
	for(int i=top;i>=1;i--) printf("%d",a[i]);
	return 0;
}
