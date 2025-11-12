#include<bits/stdc++.h>
using namespace std;
int a,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>s;
	int b[a*s];
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a;i++){
		int d;
		if(b[i]>=b[i+1]){
			d=b[i+1];
			b[i]=b[i+1];
			b[i]=d;
		}
	}
	cout<<b[1]+1;
		return 0;
}
