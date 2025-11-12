#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    int a[n*m+2];
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			s=i;
		}
	}
	if(s%n==0){
		cout<<s/n<<' ';
	}else{
		cout<<s/n+1<<' ';
	}
	if((s/n)%2==0){
		cout<<n-s/n;
	}else{
		cout<<s/n+1;
	}
	return 0;
} 
