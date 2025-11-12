#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i];
	x=a[1];	
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=m*n;j++){
			if(a[i]<a[j])
				swap(a[i],a[j]); 
		}	
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if((i%n)==0){
				if((i/n)%2==1)
					cout<<i/n<<" "<<n;
				else cout<<i/n<<" "<<1;
			}
			if(i%n!=0){
				if(i/n%2==0)
					cout<<i/n+1<<" "<<i%n;
				else cout<<i/n+1<<" "<<n-i%n+1;	
			}
			
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
