#include<bits/stdc++.h> 
using namespace std;
int n,m,s;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			s=i;
		}
	}
	int h=s/n;
	s%=n;
	if(s==0){
		s=n;
		h--;
	} 
	if(h%2==0){
		cout<<h+1<<' '<<s;
	}
	else{
		cout<<h+1<<' '<<n-s+1;
	}
	return 0;
}
