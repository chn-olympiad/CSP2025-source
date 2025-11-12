#include<bits/stdc++.h>
using namespace std;
int swap(int x,int y){
	int cmp=x;
	x=y;
	y=cmp;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,g;
	getline(cin,s);
	int i,k=0;
	i=s.size();
	for(int j=0;j<i;j++){
		if(s[j]<='9' && s[j]>='0'){
			g[k]=s[j];
			++k;
		}
	}
	for(int j=k;j>=0;j--)
		for(int m=0;m<=k;m++){
			if(g[m]<g[m+1])
				swap(g[m],g[m+1]);
		}
		for(int j=0;j<k;j++){
			cout<<g[j];
		}
	return 0;
}
