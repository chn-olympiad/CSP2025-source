#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0,0,0},asd,b=0;
string s;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);


	cin>>s;
	
	for(int i=0;i<s.size();i++){
		asd=s[i]-48;
		if(asd>=0&&asd<=9){
			b++;
			a[b]=asd;
			
		}
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
}
