#include<bits/stdc++.h>
using namespace std;
string s;
int i,j,a[10];
char b[10]={'0','1','2','3','4','5','6','7','8','9'};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size();i++){
		for(j=0;j<=9;j++){
			if(s[i]==b[j]){
				a[j]++;
				break;
			}
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
