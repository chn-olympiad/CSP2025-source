#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const  int maxn=1e5+10;
string s;
int n;
int a[10];
int top=0;
int c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[s[i]-'0']++;
			top++;
		}
	}
	c=9;
	while(c>=0){
		if(!a[c]){
			c--;
		}
		else{
			cout<<c;
			a[c]--;
		}
	}
	return 0;
}
