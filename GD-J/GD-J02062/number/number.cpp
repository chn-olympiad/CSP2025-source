#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),k=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++k]=s[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
