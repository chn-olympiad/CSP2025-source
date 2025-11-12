#include<bits/stdc++.h>
using namespace std;
int mp[21][21];
int a[21];
int b[21];
int n,m;
int cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r = 0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]==a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	sort(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int num = 0,num1 = 0;
	int ans = 0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			if(num%m==0){
				ans = num/m;
				cout<<ans<<",";
			}else if(num%m!=0){
				ans = num/m+1;
				cout<<ans<<",";
			}
			break;
		}num++;
	}
	if(ans%2==1){
		if(num%n==1){
			cout<<num/n;
		}else{
			cout<<2;
		}
	}
	//cout<<num;
	//cout<<num;
	return 0;
}

