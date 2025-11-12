#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,d;
int c[1000001];
string s;
int agg(int a){
	if(a>=m) a+=1;
else 
	return agg(a-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		
	}
	cout<<agg(d);

	
	fclose(stdin);fclose(stdout);
	return 0;
}
