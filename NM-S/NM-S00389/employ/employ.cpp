#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s,c[505]={0},a=0;
	cin>>n>>m;
	cin>>s;
	for(int j=1;j<=n;j++){
		cin>>c[j];
		if(c[j]>c[j-1]){
			a=c[j];
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
