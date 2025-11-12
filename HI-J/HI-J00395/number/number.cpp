#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt;
	for(int i=0;i<9;i++)
		if(s[i]==0){
			cnt++;
		}
	cout<<cnt<<endl; 
	return 0;	
}



