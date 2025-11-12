#include <bits/stdc++.h>
using namespace std;
int a[12][12];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int x=b[0],t;
	if (n==1&&m==1){
		cout<<n<<" "<<m;
		return 0;
	}
	else{
		for (int i=0;i<105;i++){
			for (int j=1;j<105;j++){
				if (b[j-1]<b[j]){
					t=b[j-1];
					b[j-1]=b[j];
					b[j]=t;
				}
			}
		}
		int ind=0,j=1;
		for (int t=0;t<ceil(m/2);t++){
			for (int i=1;i<=m;i++){
				if (b[ind]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				ind++;
			}
			j++;
			ind++;
			for (int i=m;i>0;i--){
				if (b[ind]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				ind++;
			}
			j++;
			ind++;
		}
	}
}
