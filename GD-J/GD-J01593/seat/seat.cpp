#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,tmp;
int a[N];
bool fa=1,fb=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) fa=0;
		else fb=0;
	}
	if(fb){
		cout<<"1 1";
		return 0;
	}
	else if(fa){
		cout<<m<<" "<<n;
		return 0;
	}
	tmp=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			tmp=n*m-i+1;
			break;
		}
	}
	if((tmp/n)%2==0&&tmp%n!=0) cout<<(tmp/n+1)<<" "<<(tmp%n);
	else if((tmp/n)%2==0) cout<<tmp/n<<" 1";
	else if((tmp/n)%2==1&&tmp%n==0) cout<<tmp/n<<" "<<n;
	else cout<<(tmp/n+1)<<" "<<(n-tmp%n+1);
	return 0;
}
