#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	if(n==1){
		cout<<s[0]-'1'+1;
		return 0;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a,a+sum+1);
	if(sum<9){
		for(int i=sum;i>=1;i--){
			ans*=10;
			ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(a[sum]==0)cout<<0;
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}