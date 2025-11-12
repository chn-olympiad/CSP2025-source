#include<iostream>
#define re register 
using namespace std;
int a[20]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	s=" "+s;
	for(re int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}		
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
