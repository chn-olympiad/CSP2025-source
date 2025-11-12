#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a,b,w;
int s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	b=a-3;
	while(b){
		for(int q=0;q<=b;q++){
			w+=1;
		}
		b-=1;
	}
	cout<<w;
	return 0;
}