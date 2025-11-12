#include<iostream>
#include<cstring>
using namespace std;
int t[10];
char s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<='9') 
		t[s-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0) {
			t[i]--;
			cout<<i;
		}
	}
	return 0;
}
