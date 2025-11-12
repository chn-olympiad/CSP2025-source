#include <bits/stdc++.h>
using namespace std;
string a;
int ans[1000005];
int cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<int(a.length());i++){
		if(a[i]<='9' && a[i]>='0'){
			ans[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<ans[i];
	}
	return 0;
}
