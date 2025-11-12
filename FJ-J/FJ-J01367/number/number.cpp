#include<bits/stdc++.h>
using namespace std;
string a;
int j[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0') j[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(j[i]>0){
			while(j[i]>0){
				j[i]--;
				cout<<i;
			}
		}
	}
	return 0;
}
