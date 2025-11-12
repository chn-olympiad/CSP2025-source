#include<bits/stdc++.h>
using namespace std;
char s[100000];
int a[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string f;
	int b;
	cin>>f;
 	for(int i=0;i<f.size()-1;i++){
 		cin>>s[i];
	 }
	for(int i=0;i<f.size()-1;i++){
 		if('0'<=s[i<='9']){
 			s[i]=a[i];
 			cout<<a[i];
		}
	}
	cout<<b;
	return 0;
}