#include<bits/stdc++.h>
using namespace std;
int b[101];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){//Why is there a warning?
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}//written by zsz0804_/GD-J00722
//i think my 4 solutions are too short
//and the problems are too easy...
