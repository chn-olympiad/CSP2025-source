#include<bits/stdc++.h>
using namespace std;
int c[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a,b,e=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		int d=c[i];
		if(d==b){
			e++;
			continue;
		}
		for(int j=i+1;j<=a;j++){
			d=d^c[j];
			if(d==b){
				e++;
				i=j;
				break;
			}
		}
	}
	cout<<e;
	return 0;
}
