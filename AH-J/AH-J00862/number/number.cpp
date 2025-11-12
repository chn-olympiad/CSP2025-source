#include<bits/stdc++.h>
using namespace std;
int t[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string in;
	cin>>in;
	int n=in.size();
	for(int i=0;i<n;i++){
		t[in[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
