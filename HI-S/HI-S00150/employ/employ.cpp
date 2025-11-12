#include<bits/stdc++.h>
using namespace std;
int  c[512];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1,cmp);
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
