#include<bits/stdc++.h>
using namespace std;
int b[20];
string a,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			char c=i+'0';
			ans=ans+c;
		}
		
	}
	cout<<ans;
	return 0;
}
