#include<bits/stdc++.h>
using namespace std;
string arr[10];
void getnum(){
	memset(arr,0,sizeof(arr));
	char t;
	while(cin>>t){
		if(t>='0'&&t<='9'){
			arr[t-'0']+=t;	
		}
	}
	for(int i=9;i>=0;i--){
		cout<<arr[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getnum();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
