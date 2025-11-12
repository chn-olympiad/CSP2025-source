#include<bits/stdc++.h>
using namespace std;
string a;
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int j='9';j>='0';j--){
		for(int i=0;a[i]!=0;i++){
			if(a[i]<='9'&&a[i]>='0'){
				if(a[i]==j){
					cout<<j-'0';
				}
			}
		}
	}
}
