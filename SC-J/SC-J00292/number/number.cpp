#include<bits/stdc++.h>
using namespace std;
int n,a[1000],cnt[1000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;//aaaaaaaaaaaaaaaaa
}