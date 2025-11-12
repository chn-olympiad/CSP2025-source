#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char n[N],a[N];
int main() {
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>n;
	int b=0;
	int m=strlen(n);
	if(m==1)cout<<n;
	for(int i=0;i<=m;i++){
		if(n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'){
			a[b]=n[i];
			b++;
		}
		if(n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'||n[i]=='0'){
			a[b]=n[i];
			b++;
		}
	}
	m=strlen(a);
	for(int i=0;i<=m;i++){
		if(a[i]=='9')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='8')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='7')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='6')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='5')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='4')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='3')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='2')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='1')cout<<a[i];
	}
	for(int i=0;i<=m;i++){
		if(a[i]=='0')cout<<a[i];
	}
	return 0;
}
