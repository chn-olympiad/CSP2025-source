#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n;
ll a[12][12],a_[110],b[12][12];
ll k=0,c=0;
bool cmp(int aa,int b){
	return aa>b;
}
int main(){
	//ÒÑ±£´æ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			k++;
			cin>>a[i][j];
			a_[k]=a[i][j];
		}
	}
	c=a[1][1];
	sort(&a_[1],&a_[k+1],cmp);
	k=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(i%2==0){
				k++;
				a[i][j]=a_[k];
			}
			else{
				k++;
				a[i][n-j+1]=a_[k];
			}
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			b[i][j]=a[j][i];
		}
	}
	//debug
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(b[i][j]==c){
				cout<<j<<" "<<n+1-i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
