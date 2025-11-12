#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k);
	for(int i=k-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
