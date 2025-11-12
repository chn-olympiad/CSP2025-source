#include<bits/stdc++.h>
using namespace std;
char a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>a;
	sort(a,a+strlen(a));
	for(int i=1;i<=strlen(a)-1;i++){
		if(a[i+1]<'0'||a[i+1]>'9'){
			for(int j=i;j>=0;j--) cout<<a[j];
			return 0;
		}
	}
	return 0;
} 
