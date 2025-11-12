#include<bits/stdc++.h>
using namespace std;
string n;
int u[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0; i<n.size(); i++){
		if(n[i]>='0'&&n[i]<='9')u[n[i]-'0']++;
	}
	for(int i=9; i>=0; i--){
		while(u[i]>0){
			printf("%d",i);
			u[i]--;
		}
	}
	return 0;
}
