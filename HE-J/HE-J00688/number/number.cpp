#include<bits/stdc++.h>
using namespace std;
string ask;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ask;
	for(int i=0;i<ask.size();i++){
		if(ask[i]>='0'&&ask[i]<='9'){
			a[ask[i]-'0']++;
		}
	}
	for(int i='9';i>='0';i--){
		for(int j=1;j<=a[i-'0'];j++){
			cout<<char(i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
