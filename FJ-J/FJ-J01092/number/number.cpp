#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	int a[10]={0};
	for(int i=0;i<b.size();i++){
		if(b[i]-'0'>=0&&b[i]-'0'<=9){
			a[b[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
