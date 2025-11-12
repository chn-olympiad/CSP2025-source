#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int u=a[1],l;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			l=i;
			break;
		}
	}
	int ansn,ansm;
	int cnt=floor(l*1.0/n);
	if(cnt%2==1){
		if(l%n==0){
			cout<<l/n<<" ";
		}else{
			cout<<cnt+1<<" ";
		}
	    cout<<n-(l%n-1);
	}else{
		if(l%n==0){
			cout<<l/n<<" ";
		}else{
			cout<<cnt+1<<" ";
		}
		cout<<l%n;
	}
	
	fclose(stdin);
	fclose(stdout);
}
