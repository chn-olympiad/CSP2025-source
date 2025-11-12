#include<bits/stdc++.h>
using namespace std;
string st;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9'){
			a[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	cout<<endl;
	return 0; 
}
