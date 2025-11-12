#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sss,an1,an2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}sss=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==sss){
			sss=i;
			break;
		}
	}
	an1=sss/n;
	an2=sss%n;
	if(an2==0){
		if(an1%2==1){
			cout<<an1<<" "<<n;
		}else if(an1%2==0){
			cout<<an1<<" "<<1;
		}
	}else{
		if((an1+1)%2==1){
			cout<<an1+1<<" "<<an2;
		}else if((an1+1)%2==0){
			cout<<an1+1<<" "<<n-an2+1;
		}
	}return 0;
}
