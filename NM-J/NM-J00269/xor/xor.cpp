#include<bits/stdc++.h>
using namespace std;
int a[5010][5010],n,sum,b[5010],asd,c[5010],k;
bool qwe;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> c
		if(c[i]==0) c[i]=1;
		if(c[i]==1) c[i]=0;
		if(c[i]==2) c[i]=1;
		if(c[i]==3) c[i]=0;
		if(c[i]==4) c[i]=3;
		if(c[i]==5) c[i]=2;
		if(c[i]==6) c[i]=1;
		if(c[i]==7) c[i]=0;
		if(c[i]==8) c[i]=7;
		if(c[i]+c[i-1]==0) cout << "1";
		if(c[i]==0&&c[i-1]==0) cout << "2";
		if(c[i]+c[i-1]!=0) cout << "0";
	}
	
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
