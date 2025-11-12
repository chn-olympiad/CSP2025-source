#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int b[N];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int n=a.size(),cnt=0;
	for(int i=0;i<n;i++)
		if(a[i]>='0'&&a[i]<='9')
			b[++cnt]=a[i]-'0';
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",b[i]);
	return 0;
}
