#include<bits/stdc++.h>
using namespace std;
int b[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
