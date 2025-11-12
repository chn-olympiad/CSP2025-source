#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int tar=a[1],ans1;
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(tar==a[i]){
			ans1=i;
		}
	}
//	cout<<ans1;
	int ansx;
	if(ans1%n==0)ansx=ans1/n;
	else ansx=(ans1/n)+1;
//	cout<<ans1%n<<endl; 
//	if(((ans1/n)+1)%2==1){
	if(ansx%2==0&&ans1%n!=0)cout<<ansx<<" "<<n-(ans1%n)+1;
	else if(ansx%2==0&&ans1%n==0)cout<<ansx<<" "<<1;
	else if(ansx%2==1&&ans1%n!=0)cout<<ansx<<" "<<(ans1%n);
	else if(ansx%2==1&&ans1%n==0)cout<<ansx<<" "<<n;
//	}
	return 0;
} 
