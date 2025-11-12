#include<bits/stdc++.h>
using namespace std;
int sz[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,qjsl=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
	int t=0;
	for(int cd=0;cd<n;cd++){
		for(int i=t;i<n-cd;i++){
			int qjjg=sz[i];
			for(int j=i+1;j<i+cd;j++){
				qjjg=qjjg^sz[i];
			}
			if(qjjg==k){
//				cout<<i<<' '<<cd<<' '<<qjjg<<endl;
				t=i+cd;
				i=i+cd;
				qjsl++;
			}
		}	
	}
	cout<<qjsl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
