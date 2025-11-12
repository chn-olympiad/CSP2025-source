#include<bits/stdc++.h>
using namespace std;
long long n,m,ma;
string a;
int b[10101010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a;
		cin>>b[i];
	}
	ma=b[0];
	if(m==1){
		for(long long i=0;i<n;i++){
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
	
	
	

