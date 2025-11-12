#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,pm,cnt,m;cin>>n>>m;int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+q+1); 
	for(int i=q;i>=1;i--){
//		cout<<a[i]<<" ";
		if(c==a[i]){
			pm=q-i+1;
		}
	}
//	cout<<pm;
	if(pm%n==0){
		cout<<n" ";
	}else{
		if(pm<n){
			cout<<pm%n:" ";
		}else if(pm>n){
			if((pm/n)+1%2==1){
				cout<<pm%n" ";
			}else{
				cout<<n-(pm%n)+1" ";
			}
		}
	}
    if(pm<=n){
		    cout<<1;
	    }else{
		    cout<<pm/n+1;
	    }
	return 0;
} 


