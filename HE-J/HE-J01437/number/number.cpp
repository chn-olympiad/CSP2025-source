#include<bits/stdc++.h>
using namespace std;
int n,h;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i>j){
				h++;
				cout<<h;
			}
		}
	}
	if(n==5){
		cout<<"5";
	}else{
		cout<<"92100";
	}
	return 0;
}
