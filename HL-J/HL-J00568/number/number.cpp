#include<bits/stdc++.h>
using namespace std;
long long a[1000100],cnt,mm[20];
long long kk,answer,k;
cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			mm[n[i]-'0']+=1;
		}
	}
	for(int i=9;i>-1;i--){
		for(int j=0;j<mm[i];j++){
			cout<<i;
		}
	}
	return 0;
}
