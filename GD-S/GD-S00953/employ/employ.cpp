#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[506];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	int t[506];
	string m;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	int j=0;
	for(int i=0;i<=n;i++){
		while(a[j+1]<i){
			j++;
			
		}
		t[i]=n-j;
	}
	for(int i=1;i<=n;i++){
		cout<<t[i]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
