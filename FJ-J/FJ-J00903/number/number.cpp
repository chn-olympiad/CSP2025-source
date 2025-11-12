#include<bits/stdc++.h>
using namespace std;
string s;
int x[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.size();
	int k=0;
	int p[l+1];
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			p[i]=s[i]-'0';
			x[p[i]]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(x[i]>=1){
			for(int j=1;j<=x[i];j++){
				cout << i;
			}
		}
	}
	return 0;
}
