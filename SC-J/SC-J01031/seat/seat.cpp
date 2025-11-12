#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int c[n][m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-i-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n*m;i++){
		if(a[i]!=b){
			sum++;
		}
		else if(a[i]==b){
			break;
		}
	}
	cout<<(sum/n)+1<<" ";
	if((sum/n+1)%2==0){
		cout<<n-(sum%n)<<" ";
	}
	else if((sum/n+1)%2!=0){
		cout<<sum%n+1<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 