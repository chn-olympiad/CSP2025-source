#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
string s;
long long a[10],n,m;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
		m=s.size();
	for(int i=0;i<m;i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
			
		}
	}
	

	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
