#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),p=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			p++;
			a[p]=(int)s[i]-48;
		}
	}
	sort(a+1,a+1+p);
	for(int i=p;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
