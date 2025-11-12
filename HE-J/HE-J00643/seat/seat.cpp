#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt=0;
int a[100001],s[1999][1999];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt++;
	}
	x=a[1];
	sort(a,a+n*m+1);
	if(n==1){
		for(int i=1;i<=m;i++){
			if(a[i]==x){
				cout<<"1"<<" "<<m-i+1;
				return 0;
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]==x){
				cout<<n-i+1<<" "<<"1";
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
