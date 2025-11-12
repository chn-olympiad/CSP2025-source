#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt++;
			ans[cnt] = a[i]-'0';
		}
	}
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d",ans[i]);
	}
	return 0;
}