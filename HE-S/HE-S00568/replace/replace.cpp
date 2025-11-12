#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	string a[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	string b[q][2];
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>b[i][j];
		}
	}
	for(int j=0;j<q;j++){
		for(int i=0;i<n;i++){
			if(a[j][0]==a[i][0]){
				ans++;
			}	
		}
	}
	cout<<ans+1;
	return 0;
} 
