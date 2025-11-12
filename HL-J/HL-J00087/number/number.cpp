#include<bits/stdc++.h>
using namespace std;
int a,b;
int n[10],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a!=0){
		b=a%10;
		n[b]+=1;
		a=a/10;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			s+=s*10+i;
		}
	}
	cout<<s;
	return 0;
}
