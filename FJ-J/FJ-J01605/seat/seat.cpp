#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ll{
	int mark;
	int num;
};ll a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i].mark;
		a[i].num=i;
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=t;i++){
		for(int j=i;j<=t;j++){
			if(a[i].mark<a[j].mark)swap(a[i],a[j]);
		}
	}
	int nm;
	//for(int i=1;i<=t;i++)cout<<a[i].mark<<" "<<a[i].num<<"\n"; 
	for(int i=1;i<=t;i++){
		if(a[i].num==1){
			nm=i;
			break;
		}
	}
	//cout<<nm<<"\n";
	if(nm>n) {
		cout<<nm/m+1<<" ";
		if((nm/m)%2==0)cout<<n-nm%m;
		else cout<<nm%m;
	}
	else cout<<1<<" "<<nm;
	return 0;
}
