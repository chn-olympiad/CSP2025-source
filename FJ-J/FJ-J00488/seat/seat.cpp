#include <bits/stdc++.h>
using namespace std;
long long n,m,c,cnt,b[100005];
long long a[1005][1005];
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m; 
	for(int i=0;i<n*m;i++){
		cin>>b[i]; 
	}
	c=b[0];
	sort(b,b+n*m,cmp);  
	for(int i=1;i<=m;i++){ 
		if(i%2==1){ 
			for(int j=1;j<=n;j++){
				a[i][j]=b[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j]=b[cnt]; 
				cnt++;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j][i]==c){
				cout <<j<<" "<<i;
			}
		} 
	}
	return 0;
}  
