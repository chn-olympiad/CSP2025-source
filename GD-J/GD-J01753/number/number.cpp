#include<bits/stdc++.h>
using namespace std;
char a[1145140];
int k = 0,l;
int ans[1145140];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l = strlen(a);
	for(int i = 0;i < l;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			ans[++k] = a[i] - '0';
		}
	}
	sort(ans + 1,ans + k + 1);
	for(int i = k;i >= 1;i--){
		cout<<ans[i];
	}
	return 0;
}
