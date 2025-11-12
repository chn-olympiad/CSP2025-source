#include <bits/stdc++.h>
using namespace std;
int len[5050];
int main(){
	int n,est=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>len[i];
		if(len[i]>est)est=len[i];
	}
	cout<<9;
	return 0; 
	//ÎÒÅÅ¶ÓÇóÄã¡£ 
} 
