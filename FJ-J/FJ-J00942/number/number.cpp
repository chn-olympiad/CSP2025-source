#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long z=s.size();
	for(long long i=0;i<z;i++){
		for(long long j='0';j<='9';j++){
			if(s[i]==j){
				a[j-48]++;
			}
		}
	} 
	for(long long i=9;i>=0;i--){
		while(a[i]!=0){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
