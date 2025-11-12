#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    cin>>s;
	int l=s.size();
    for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int t=s[i]-'0';
			a[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
    return 0;
}
