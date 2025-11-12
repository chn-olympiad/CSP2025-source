#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	if(n/10==0){
		cout<<n;
		return 0;
	}
	if(n/10>1&&n/10<10){
		int x=n%10;
		int y=n/10;
		if(x>y){
			cout<<n%10*10+n/10%10;
			return 0;
		}
		else {
			cout<<y*10+x;
			return 0;
		}
	}
	char c;
	if(cin>>n>>c||cin>>c>>n){
		cout<<n;
		
	}
	
	return 0;
}

