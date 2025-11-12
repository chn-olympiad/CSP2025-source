#include<bits/stdc++.h >
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size();
	if(n==1){
		cout<<s;
		return 0;
	}
	int a[100010]={},h=0;
	for(int i=0;i<=n;i++){
		for(int j=48;j<=57;j++){
			if(("%d",s[i])==j){
				a[h]=("%d",s[i]);
				a[h]-=48;
				h++;
			}
		}
	}
	sort(a,a+h);
	for(int i=h-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
