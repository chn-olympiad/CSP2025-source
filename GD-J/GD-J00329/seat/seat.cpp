#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10009],k,s[108][108];
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m*n;j++){
			if(a[j+1]>a[j]){
				swap(a[j+1],a[j]);
			}
		}
	}
	//for(int i=1;i<=n*m;i++){
	//	cout<<a[i]<<' ';
	//}
	for(int i=1;i<=m*n;i++){
		int f=i/n;
		if(i%n==0)
			f--;
		if(f%2==1){
			if(i%n!=0){
				s[n-i%n+1][i/n+1]=a[i];
				//cout<<n-i%n+1<<' '<<i/n+1<<' '<<1<<endl;
			}else{
				s[1][i/n]=a[i];
				//cout<<1<<' '<<i/n<<' '<<2<<endl;
			}
		}else{
			if(i%n!=0){
				s[i%n][i/n+1]=a[i];
				//cout<<i%n<<' '<<i/n+1<<' '<<3<<endl;
			}else{
				s[n][i/n]=a[i];
				//cout<<n<<' '<<i/n<<' '<<4<<endl;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<s[i][j];
			if(s[i][j]==k)
				cout<<j<<' '<<i;
		}
	}
	return 0;
} 
