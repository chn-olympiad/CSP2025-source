#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int n[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;int(a[i])!=0;i++){
		if(a[i]>='0' and a[i]<='9'){
			n[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}


