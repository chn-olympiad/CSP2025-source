#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ","w",stdout);
		int m,n;
		cin>>m>>n;
		for(int i=0;i<m;i++){
			char a;
			cin>>a;
		}
		for(int i=0;i<m;i++){
			int b;
			cin>>b;
		}
		int cnt=1;
		for(int i=m;i>0;i--){
			cnt=cnt*m;
		}
	return 0;
}
