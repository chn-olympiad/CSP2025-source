#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],f;
bool cmp(int x,int y){
	return x>y;
}
void p(int x){
	cout<<x/n+(x%n!=0)<<" ";
	if((x/n+(x%n!=0))%2==1){
		cout<<x-(x/n-(x%n==0))*n;
	}
	else{
		cout<<n-(x-(x/n-(x%n==0))*n)+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			p(i);
			return 0;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
