#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],a1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9') a[++a1]=b[i]-'0';
	}
	sort(a+1,a+1+a1);
	for(int i=a1;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}