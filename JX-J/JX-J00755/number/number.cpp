#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
char c[N];
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int len=strlen(c);
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[++cnt]=c[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0;
}
