#include<bits/stdc++.h>
using namespace std;
int n,m,rans,rk;
struct student{
	int k;
	int ans;
};
int cmp(student x,student y){
	return x.ans>y.ans;
}
student arr[1100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",srdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i].ans;
		arr[i].k=i;
	}
	rans=arr[1].ans;
	sort(arr,arr+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i].ans==rans){
			rk=i;
		}
	}
	int q=rk/m+1;
	cout<<q<<" ";
	if(q%2==1){
		cout<<rk-(q-1)*n+1;
	}
	else{
		cout<<n-(rk-(q-1)*n);
	}
	return 0;
}
