#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size(),cnt=0;
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++cnt]=a[i]-'0';
		}
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",b[i]);
	}
	return 0;
}
