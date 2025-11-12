#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int l=s.size()-1,j=1;
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9') {
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
