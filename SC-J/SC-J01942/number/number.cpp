#include<bits/stdc++.h>
using namespace std;
const long long S=1e6+10;
string s;
long long n,a[S];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	if(s.size()==1){
		cout<<s;
	}
	else{
		for(int i=1;i<=s.size();i++){
		   long long y=s.size();
		   for(int k=1;k<=s.size();k++){
		   	    y=y*10;
		   }
		   a[i]=s[i]*y;
		   y--;
		}	
		sort(a,a+1+n);
	    cout<<a[1];
	}
	return 0;
} 