#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		if(a[cnt]==0){
			cout<<0;
			break;
		}
		cout<<a[i];
	}
	return 0;
}
