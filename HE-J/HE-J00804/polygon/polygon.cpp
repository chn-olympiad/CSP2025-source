#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=1,m=1;
	int s[10];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i]>s[j]){
				cout<<s[i]+s[j];
			}else{
				cout<<s[i]-s[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=1;
			int xx;
			cin>>xx;
			x=xx*x+(xx-x);
		}
}
	return 0;
}
