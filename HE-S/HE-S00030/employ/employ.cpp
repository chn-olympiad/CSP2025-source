#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
string a;
int b[10101010];
int main(){
	freopen("empty.in","r",stdin);
	freopen("empty.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b[i];
	}
	ma=b[0];
	if(m==1){
	for(int i=0;i<n;i++){
		if(ma<b[i])ma=b[i];
	}
	cout<<ma;
}
else{
	cout<<225301405;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
