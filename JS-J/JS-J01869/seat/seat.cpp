#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105]={0};
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	a[x]=2;
	for(int i=0;i<n*m-1;i++){
		int y;
		cin>>y;
		a[y]=1;
	}
	int s=0;
	for(int j=100;j>0;j--){
		if(a[j]==1){
			s+=1;
		}
		if(a[j]==2){
			s+=1;
			break;
		}
	}
	int n1;	
	int m1;
	if(s%n==0){
		n1=s/n;
		m1=n;
	}else{
		n1=s/n+1;
		m1=s%n;
	}

	if(n1%2==0){
		cout<<n1<<' '<<n-m1+1<<endl;
	}else{
		cout<<n1<<' '<<m1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
