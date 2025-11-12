#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'0';
		if(t>=0&&t<=9){
			cnt++;
			a[cnt]=t;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
