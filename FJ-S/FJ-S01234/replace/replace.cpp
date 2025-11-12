#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,s,q=0;
	cin>>a>>s;
	string d[a][2],f[s][2];
	for(int i=0;i<a;i++){
		cin>>d[i][0]>>d[i][1];
	}
	for(int i=0;i<s;i++){
		cin>>f[i][0]>>f[i][1];
		for(int z=0;z<a;z++){
			if(f[i][0] == d[z][0] && f[i][1] == d[z][1]){
				q++;
			}
		}
	}
	cout<<q;
	fclose(stdin);fclose(stdout);
	return 0;
}
