#include<bits/stdc++.h>
using namespace std;
string s;int a[12],tmp,cnz;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(isdigit(s[i])){
			tmp=s[i]-'0';
			if(tmp==0){
				cnz++;
			}else{
				a[tmp]++;
			}
		}
	}
	for(int i=9;i>=1;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	while(cnz){
		cnz--;
		cout<<0;
	}cout<<endl;
	return 0;
}