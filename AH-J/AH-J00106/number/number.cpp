#include<bits/stdc++.h>
using namespace std;
string s;
int x[30];
int n,m,p,f;
long long int zkx=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		m=s[i];
		if(m>=48 && m<=57){
			p=m-48;
			x[p]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		f=x[i];
		for(int j=1;j<=f;j++){
			zkx=zkx*10;
			zkx+=i;
		}
	}
	
	
	cout<<zkx;


	return 0;
}
