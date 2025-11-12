#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k1=a[1];
	sort(a+1,a+1+(n*m));
	reverse(a+1,a+1+(n*m));
	int i=1,j=1,k2=1,l=1;
	while(j<=m){
		if(a[l]==k1){
			cout<<j<<' '<<i<<endl;
			break;
		}
		if(i==n && k2==1){
			j++;
			k2=-1;
		}else if(i==1 && k2==-1){
			j++;
			k2=1;
		}else{
			i+=k2;
		}
		l++;
    }
	return 0;
}
