#include<bits/stdc++.h>
using namespace std;
string s;
int a[20],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int l=9;l>=0;l--){
		if(a[l]>0){
			for(int i=1;i<=a[l];i++){
				cout<<l;
			}
		}
	}
	return 0;
}
