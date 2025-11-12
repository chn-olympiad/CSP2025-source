#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define M 1010
using namespace std;
ll n,m,a[N],g,s=1,d=1;
string fjksdhfjjdskfhidshfidsnfkdjshfucbnreicnidswuhcbiweuhihfdisucniuerhafh;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>fjksdhfjjdskfhidshfidsnfkdjshfucbnreicnidswuhcbiweuhihfdisucniuerhafh;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			g--;
		}
	}
	g+=n;
	m=min(m,n-m);
	for(int i=1;i<=m;i++){
		s*=n-i+1;
		d*=i;
		if(s%d==0){
			s/=d;
			d=1;
		}
		while(s%2==0&&d%2==0){
			s/=2;
			d/=2;
		}
		while(s%3==0&&d%3==0){
			s/=3;
			d/=3;
		}
		while(s%5==0&&d%5==0){
			s/=5;
			d/=5;
		}
	}
	cout<<s/d<<endl;
    return 0;
}
