#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(int i='9';i>='0';i--){
		for(int j=0;j<=x.size();j++){
			if(x[j]==i)cout<<x[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	//system("fc number.out ans.out");
	return 0;
}
