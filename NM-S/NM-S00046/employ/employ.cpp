#include<bits/stdc++.h>

using namespace std;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int s[11]={0};
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		s[t]++;
	}
	int x=1;
	for(int i=0;i<=9;i++){
		x*=max(1,s[i]);
	}	
	cout<<x<<endl;
	//fclose(stdin);
	//fclose(stdout):
	return 0;
}

