#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[9]={0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int ans=0;
	for(int	i=9;i>=0;i-- ){
		while(a[i]>0){
			ans=ans*10+i;
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
}