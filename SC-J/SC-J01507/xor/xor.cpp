#include<bits/stdc++.h>
using namespace std;
int a[100005],b,n,sum;
int p(int a,int b){
	if(a==b) return 0;
	else return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==b){
			sum++;
		}
	}
	int pro=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b){
			pro=p(a[i],pro);
		}
		if(a[i]==b) pro=0;
		if(pro==b) sum++,pro=0;
	}
	cout<<sum;
	return 0;
}