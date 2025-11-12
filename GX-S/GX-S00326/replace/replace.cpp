#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a;cin>>a;
	cout<<a;
		long long n,m,t;cin>>t;cin>>n>>m;
	long long arr[10000]={ };
for(int q=0;q<t;q++){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int w;w<100000;w++){
		if(m<n){
			cout<<w<<endl;
			}
		else if(n<m){
			cout<<w<<endl;
		}
		else if(n==m){
			cout<<w<<endl;
		}
	  }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
