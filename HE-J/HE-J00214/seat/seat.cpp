#include<bits/stdc++.h>
using namespace std;
int mp[10][10],n,m;
int a[101],b[101],man;
int main(){
//	freopen("seat.in","r"stdin);
//	freopen("seat.out","r"stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}

	sort(a,a+n*m+1);
	for(int i=1;i<=m;i++)
		b[i]=a[n*m+i+1];
	for(int i=1;i<=n*m;i++){
		if(b[i]==)
	}
	else if(m==1&&n==10){
		cout<<1<<" "<<man;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=b[i*j];
				}
			}
		else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[i*j];
			}
		}
		for(int )
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
