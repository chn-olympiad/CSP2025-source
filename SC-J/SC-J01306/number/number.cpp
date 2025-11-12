#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
int ppp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 	string s;
	cin>>s;
	int l=s.size();
	int n=1;
	for(int i=0;i<l;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}sort(a+1,a+n+1,ppp);
	for(int i=1;i<n;i++){
		cout<<a[i];
	}
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	return 0;
}