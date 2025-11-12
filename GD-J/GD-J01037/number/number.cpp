#include<bits/stdc++.h>
using namespace std;
int dui[15],ans=0;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	memset(dui,0,sizeof(dui));
	for(int i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			dui[n[i]-'0']++;
			ans++;
		}
	}
	for(int i=9;i>=0;i--){
		while(dui[i]--) printf("%d",i);
	}
} 
