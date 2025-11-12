#include<bits/stdc++.h>
using namespace std;
int num[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string h;
	cin>>h;
	for(int i=0;i<h.size();i++){
		char k=h[i];
		int l=k-'0';
		num[l]++;
	}for(int i=9;i>=0;i--){
		for(int j=num[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;
}
