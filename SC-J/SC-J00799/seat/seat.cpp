#include <bits/stdc++.h>
using namespace std;
string a;
long long n,m,b[1010],xm,c[100][100];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>b[i];
		if(i==1){
			xm=b[i];
		}
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(b[i]==xm){
			long long w,e,h;
			h=ceil(i/n);
			if(i%n!=0){
				h++;
			}
			e=i-n*(h-1);
			if(h%2==0){
				w=m-e+1;
				cout<<h<<" "<<w;
			}else{
				cout<<h<<" "<<e;
			}
		}
	}
} 