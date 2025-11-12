#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int b[1001]={};
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
    k=b[1];
	sort(b+1,b+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==k){
			k=i;
			break;
		}
	}
    int n1=(k-1)/n+1;
	cout<<n1;
	int n2=(k-1)%n+1;
	if(n1%2==1){
		cout<<" "<<n2;
	}else{
		cout<<" "<<n-n2+1;
	}
	return 0;
}
