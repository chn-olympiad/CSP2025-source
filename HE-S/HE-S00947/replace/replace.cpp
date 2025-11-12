#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	srand(time(0));
	for(int i=1;i<=m;i++)cout<<rand()%m<<'\n';
	return 0;
	fclose(stdin);
	fclose(stdout);
}
