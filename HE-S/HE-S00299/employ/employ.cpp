#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,sum=0,sum1;
	string s;
	int c[10001],d[10001];
    cin>>m;
	cin>>n;
	for(int i=1;i<=m;i++){
	cin>>s;
	}
	for(int i=1;i<=m;i++){
	cin>>c[i];
		
	}
	for(int j=1;j<=m;j++){
		if(s[j]=='0'){
			sum++;
			d[j]==sum;
		}
		if(s[j]=='1') sum1++;
	}
	for(int i=1;i<=m;i++){
		if(c[i]<d[i]){
			m--;
		}
	}
	cout<<sum1;
return 0;
}  
