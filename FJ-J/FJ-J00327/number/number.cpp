#include<bits/stdc++.h>
using namespace std;
int h[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	while(cin>>a){
		if('0'<=a&&a<='9'){
			h[a-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=h[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}

