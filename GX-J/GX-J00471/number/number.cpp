#include<bits/stdc++.h>
using namespace std ;
int tong[10];
int main()
{
	
	freopen("number.in","r" ,stdin);
	freopen("number.out","w" ,stdout);
	string a;
	int gs=0;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			gs++;
			tong[a[i]-'0']++;
		}	
	}
	for(int i=9;i>=0;i--){
		if(tong[i]>0){
			for(int j=0;j<tong[i];j++){
				cout<<i;
			}
		}
	}
		
	return 0;
}	
