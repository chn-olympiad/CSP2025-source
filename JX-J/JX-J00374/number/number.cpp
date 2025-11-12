#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s;
int a[1000010];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(isdigit(s[i])){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
