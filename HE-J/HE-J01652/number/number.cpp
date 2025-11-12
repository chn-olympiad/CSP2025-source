#include<bits/stdc++.h>
using namespace std;
string st;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=15;i++){
		a[i]=0;
	}
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9'){
			int x=st[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
