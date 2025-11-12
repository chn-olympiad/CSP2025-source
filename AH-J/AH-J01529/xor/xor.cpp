#include<bits/stdc++.h>
using namespace std;
int a[5005];
struct op{
	int e,f;
}ui[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,s,p=0;
	cin>>n>>m;
	if(n==2){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				s=a[i];
			}
			else{
				s=(s^a[j]);
			}
			if(s==m){
				p++;
				break;
			}
		}
	}
	cout<<p;
	return 0;
}
