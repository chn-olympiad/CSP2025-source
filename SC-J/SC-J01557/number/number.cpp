#include<bits/stdc++.h>
using namespace std;
int hash[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;cin>>n;
	int t=n.size();
	for(int i=0;i<t;i++){
		if('0'<=n[i]&&n[i]<='9')hash[n[i]-'0'-1]++;
	}
	int a=0;
	for(int i=1;i<9;i++){
		if(hash[i]!=0)a=1;
	}
	if(a==0)cout<<0;
	else{
		for(int i=9;i>=0;i--){
			for(int j=0;j<hash[i];j++){
				cout<<i+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}