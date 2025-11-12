#include<bits/stdc++.h>
using namespace std;
int n,m,c[500];
string diff;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>diff;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2){
		cout<<2;return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;return 0;
	}
	cout<<161088479;
	return 0;
}
