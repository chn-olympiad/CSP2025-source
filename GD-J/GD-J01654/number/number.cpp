#include<bits/stdc++.h>
using namespace std;
string a;
int n[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9)n[a[i]-'0']++;
	}for(int i=9;i>=0;i--){
		while(n[i]--)cout<<i;
	}
	return 0;
}
