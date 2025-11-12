#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,t;cin>>t;cin>>n>>m;
	long long arr[10000]={ };
for(int q=0;q<t;q++){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int w;w<100000;w++){
		if(m<n){
			cout<<w;
			}
		else if(n<m){
			cout<<w;
		}
		else if(n==m){
			cout<<w;
		}
	  }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
