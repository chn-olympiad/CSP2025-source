#include<cstdio>
#include<iostream>
using namespace std;
string n;
int r[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++) if(isdigit(n[i])) r[n[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=r[i];j++) cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
