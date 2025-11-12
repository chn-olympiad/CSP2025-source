#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],e=1,b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int s=a[1];
	
	sort(a+1,a+l+1);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			int c=1;
			for(int j=c;j<=n;j++){
				b[j][i]=a[l];
				l--;
				if(b[j][i]==s){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			int c=n;
			for(int j=c;j>=1;j--){
				b[j][i]=a[l];
				l--;
				if(b[j][i]==s){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
