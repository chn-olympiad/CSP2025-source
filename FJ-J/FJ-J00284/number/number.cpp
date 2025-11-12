#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			int l=s[i]-'0';
			a[l]++;
		}
	}
	bool flag=false;
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			if(i==0&&!flag){
				cout<<0;
			}
			else{
				while(a[i]--){
					cout<<i;
				}
			}
			
			flag=true;
		}
	}
	return 0;
}