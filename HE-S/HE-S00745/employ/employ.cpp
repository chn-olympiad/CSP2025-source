#include<bits/stdc++.h>
using namespace std;
int n,m=2,p[505],c[505],s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	for(int i=n;i<=m;i++){
		if(s[i]==0){
			n--;
		}else if(s[i]==1){
			n++;
		}
	}
	for(int i=0;i<=n;i++){
		if(p[i]<=c[i]){
			c[i]=0;
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
}
