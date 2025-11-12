#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000050],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int w=s[i]-'0';
		if(w>=0&&w<=9){
			a[++cnt]=w;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
