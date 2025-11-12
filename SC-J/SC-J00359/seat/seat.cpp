#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int l;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			l=i;
			break;
		}
	}
	int p=1,q=1,r=1;
	while(p*q<=n*m){
		if(r==l){
			cout<<p<<" "<<q;
			return 0;
		}
		if((p%2==1 and q==n) or (p%2==0 and q==1)){
			p+=1;
		}else{
			if(p%2==1)q+=1;
			else q-=1;
		}
		r++;
	}
	return 0;
}