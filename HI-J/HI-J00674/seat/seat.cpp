#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2){
	return a1>a2;
}
int s[101];
int main(){
	int n,m,c,r,rcj,rpm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		rcj=s[1];
	}
	sort(s,s+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==rcj){
			rpm=s[i];
		}
	}
	c=ceil(rpm/n);
	cout<<c;
	return 0;
}
