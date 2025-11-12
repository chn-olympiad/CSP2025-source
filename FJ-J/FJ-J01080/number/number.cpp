#include<bits/stdc++.h>
using namespace std;
int t[15]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0')t[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(t[i]==0)continue;
		while(t[i]>0){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}
