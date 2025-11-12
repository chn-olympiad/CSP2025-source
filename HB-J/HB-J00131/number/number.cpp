#include <bits/stdc++.h>
using namespace std;
string a;
int s[11],flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		s[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(s[i]==0){
			flag++;
		}
		if(i==0 && (flag==9||flag==10)){
			cout<<0;
			return 0;
		}
		while(s[i]>0){
			cout<<i;
			s[i]--;
		}
		
	}
	return 0;
}
