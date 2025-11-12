#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,q[3],m;
	cin>>a;
	for(int i=0;i<a;i++){
		m=0;
		cin>>b;
		for(int j=0;j<b;j++){
			cin>>q[0]>>q[1]>>q[2];
			sort(q,q+3);
			m=m+q[2];
		}
		cout<<m<<endl;	
	}
	return 0;
}
