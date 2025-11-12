#include<bits/stdc++.h>
using namespace std;
int ans[1000001],cnt;
string a,b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if ((a[i]-'0'==0)||(a[i]-'0'==1)||(a[i]-'0'==2)||(a[i]-'0'==3)||(a[i]-'0'==4)||(a[i]-'0'==5)||(a[i]-'0'==6)||(a[i]-'0'==7)||(a[i]-'0'==8)||(a[i]-'0'==9)){
			ans[cnt]=a[i]-'0';
			b+="a";
			cnt++;
		}
	}
	sort(ans,ans+b.size(),cmp);
	for(int i=0;i<b.size();i++){
		cout<<ans[i];
	}
	return 0;
}
