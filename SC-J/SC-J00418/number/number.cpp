#include<bits/stdc++.h>
using namespace std;
string q;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	int n=q.size();
	bool k=0;
	for(int i=0;i<n;i++){
		if(isdigit(q[i])){
			a[q[i]-'0']++;
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