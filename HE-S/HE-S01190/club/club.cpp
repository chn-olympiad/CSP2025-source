#include<bits/stdc++.h>
using namespace std;
int main(){
int n,b,c,d,s;
	cin>>n;
	b=0;
	freopen("club.in""r"stdin)
	freopen("club.out""w"stdout)
	int a[];
	int club[1,2,3];
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j]>>c;
			if(c==club[1]){
				b=c+b;
			}
			if(c==club[2]){
				d=c+d;
			}
			if(c==club[3]){
				s=c+s;
			}
		}
		cout<<b<<" "<<d<<" "<<s<<endl;
	}

