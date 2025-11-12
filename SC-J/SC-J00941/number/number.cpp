#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

string x;
long long a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>x;
	
	for(int i=0;i<x.size();i++)
		if(x[i]>='0'&&x[i]<='9')a[x[i]-'0']++;
	
	for(int i=10;i>=0;i--){
		//cout<<i<<" "<<a[i]<<endl;
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
	
	return 0;
} 