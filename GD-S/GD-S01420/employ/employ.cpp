#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],num=0,p=0;
	char s[505];
	cin>>n>>m;
	num=n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			num--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
