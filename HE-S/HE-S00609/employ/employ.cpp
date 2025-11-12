#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int j=0;
	for(int i=1;i<=a.length();i++){
		if(a[i]=='1'){
			j++;
		}
	}
	cout<<j;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
