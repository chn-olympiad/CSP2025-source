#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	int m;
	cin>>s;
	for(int i=1;i<=10e5;i++){
		if(s%i==0){
			m=i;
		}
	}
	if(m==1)
	cout<<s;
	return 0;
}
