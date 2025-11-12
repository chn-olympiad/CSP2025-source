#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(i==1)a=s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			a=i;
			break;
		}
	}
	if(a<=n){
		cout<<1<<" "<<n;
	}else{
		int c=a/n;
		int r=a%n;
		if(r==0){
			cout<<c<<" ";
			if(c%2==0){
				cout<<1;
			}else{
				cout<<n;
			}
		}else{
			cout<<c+1<<" ";
			if(c%2==0){
				cout<<n-r-1;
			}else{
				cout<<n-r+1;
			}
		}
	}
	return 0;
}
