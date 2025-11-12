#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length(),m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	if(a[m]==0){
		printf("0\n");
		return 0;
	}
	for(int i=m;i>=1;i--){
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
