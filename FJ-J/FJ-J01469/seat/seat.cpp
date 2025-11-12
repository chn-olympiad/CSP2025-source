#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int s[105],n,m,a;
bool cmp(int a,int b){return a>b;}
int search(int n){
	for(int i=0;i<n*m;i++)if(s[i]==n)return i;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>s[i];
	a=s[0];
	sort(s,s+n*m,cmp);
	//for(int i=0;i<n*m;i++)cout<<s[i]<<' ';
	//cout<<endl;
	a=search(a);
	//cout<<a<<endl;
	cout<<1+a/n<<' ';
	if((a/n)%2==0)cout<<a%n+1;
	else cout<<n-a%n;
	return 0;
}
