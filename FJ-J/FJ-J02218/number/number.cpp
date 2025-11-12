#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string ss;
	int a[1000005]={};
	cin>>ss;
	int cnt=0;
	for(int i=0;i<1000005;i++){
		if(ss[i]<='9'&&ss[i]>='0'){
			a[cnt]=ss[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	long long ans=0;
	for(int i=cnt;i>=0;i--){
		if(a[i]==0)ans=ans*10;
		else ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
}

