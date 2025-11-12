#include<bits/stdc++.h>
using namespace std;
const int N=10;
string s;
int a[N]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!(s[i]<='z'&&s[i]>='a')){
			int j=int(s[i]-'0');
			a[j]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 