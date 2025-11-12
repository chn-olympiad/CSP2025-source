#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[12];
	for(int i=0;i<=9;i++)n[i]=0;
	int u=(a.size()-1);
	//cout<<u;
	for(int l=0;l<=u;l++){
		if(a[l]<='9'&&a[l]>='0')n[a[l]-'0']++;
	}
	//for(int i=0;i<=9;i++)cout<<n[i]<<endl;
	for(int i=9;i>-1;i--){
		for(int j=1;j<=n[i];j++)cout<<i;
	}
 return 0;
}
