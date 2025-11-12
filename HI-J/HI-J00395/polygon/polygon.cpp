#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	string n;
	cin>>n;
	
	int cnt;
	for(int i=0;i<5000;i++)
		for(int m=0;m<=3;m++)
			if(n[m]>=10000){
				cnt++;
			}
		
	cout<<cnt%'998'<<cnt%'244'<<cnt%'353'<<endl;
	return 0;
}
