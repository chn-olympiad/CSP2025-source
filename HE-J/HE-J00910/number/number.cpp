#include<bits/stdc++.h>
using namespace std;
string s[1000000]; 
int a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1,m=1;
	cin>>s[i++];
	for(int j=1;j<=i;j++){
		if(s[j-1]>=0)){
			a[m++]=int(s[j-1]);
		}
	}
	sort(s[1]:s.end());
	for(int i=1;i<=s_size();i++){
		cout<<s[i];
	}
	return 0;
}
