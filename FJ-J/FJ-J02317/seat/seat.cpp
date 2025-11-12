#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0],num;
	if(n==1&&m==1){
		cout<<"1"<<" "<<"1"<<endl;
		return 0;
	}
	int sum=n*m;
	sort(a,a+sum);
	for(int i=0;i<n*m;i++){
		cout<<a[i]<<endl;
	}
	for(int i=0;i<n*m;i++){
		if(ans==a[i]){
			num=i+1;
		}
	}
	num=n*m-num+1;
	if(n==1){
		cout<<1<<" "<<num<<endl;
	}else{
		cout<<num<<" "<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

