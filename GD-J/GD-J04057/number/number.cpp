#include <bits/stdc++.h>
using namespace std;
int nb(char ppk){
	for(int i=0;i<10;i++){
		if(ppk-'0'==i){
			return 1;
		}
	}
	return 0;
}
int main(){
	int mmu[10]={0};
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string ppk;
	int op=0;
	cin>>ppk;
	for(int i=0;i<ppk.size();i++){
		if(nb(ppk[i])==1){
			mmu[ppk[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<mmu[i];j++){
			cout<<i;
		}
	}
	return 0;
}
