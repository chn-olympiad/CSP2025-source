#include<bits/stdc++.h>
using namespace std;
string a;
int b[11];
int x,y,z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int lena=a.size();
	for(int i=0;i<lena;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=1;i<10;i++){
		if(b[i]!=0){
			x++;
		}
	}
	if(x==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
