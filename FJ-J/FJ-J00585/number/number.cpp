#include<bits/stdc++.h>
using namespace std;
string s;
int c[1000001],t=0;
int main(){
	cin>>s;
	int l=s.size();
	for(int i=0;i<l+1;i++){
		if(s[i]>=0&&s[i]<=9){
			c[t]=s[i];
			cout<<c[t]<<endl;
			t++;
		}
	}
	sort(c+0,c+t);
	for(int i=0;i<t;i++)cout<<c[i]<<endl;
	return 0;
}
/*
lenght length legnht leghtn lgneht
*/
