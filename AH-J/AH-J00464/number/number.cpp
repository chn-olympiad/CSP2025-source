#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;cnt--;i--){
		cout<<a[i];
	}
	return 0;
}
