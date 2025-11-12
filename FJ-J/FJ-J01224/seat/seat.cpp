#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[110],b[110];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;i<n*m;i++){
			if(b[j]<b[j+1]){
				int c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
		}
	} 
	int paiming=0,lie,hang;
	for(int i=0;i<n*m;i++){
		if(b[i]==a[0]) paiming=i+1;
	}
	lie=paiming/n+1;
	if(lie%2==1){
		hang=paiming%n;
		cout<<lie<<" "<<hang;
	}else{
		hang=n-(paiming%n);
		cout<<lie<<" "<<hang;
	}
	return 0; 
}
