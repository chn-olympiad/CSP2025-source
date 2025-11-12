#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int bao=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==bao){
			num=i;
			break;
		}
	}
	int a1=num/n;
	int a2=num%n;
	if(a2==0){
		if(a1%2==1){
			cout<<a1<<" "<<n;
		}else{
			cout<<a1<<" "<<1;
		}
	}else{
		if((a1+1)%2==1){
			cout<<a1+1<<" "<<a2;
		}else{
			cout<<a1+1<<" "<<n-a2+1;
		}
	}
	return 0;
}
