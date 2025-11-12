#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2; 
}a[5000005];
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int j=1;j<=q;j++){
		string y,h;
		int cnt=0;
		cin>>y>>h;
		for(int i=1;i<=n;i++){
			if(y==a[i].s1&&h==a[i].s2){
				cnt++;
			}
			
		} 
		cout<<cnt<<endl;
	}
	return 0;
}
