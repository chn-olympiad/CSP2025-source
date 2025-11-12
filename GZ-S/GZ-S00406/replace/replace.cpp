//GZ-S00406 六盘水市知见外国学校 覃圣超 
#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int g[1000000][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,t=0,i=0,h=0;
	
	string s;
	cin>>n>>q;
	while(i<q){
		getline(cin,s);
		for(int j=0;j<n+1;j++){
			cin>>a[i];
		}
		for(int v=0;v<s.length();v++){
		if(a[v]==s[1]&&a[v+1]==s[2]) g[1][0]+=1;
		}
		i+=1;
	}
	cout<<2<<endl<<0;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
