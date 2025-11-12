#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
long long n,m,c,r,a[110],s,b[11][11];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s) s=i;
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				s--;
				if(s==0){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				s--;
				if(s==0){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
//cout<<fixed<<setprecision(2)<<a;
//memset(a,0,sizeof(a));
//if(s.find(a)!=string::npos);
//__gcd(3,9)
//pow abs
//map<string,int> m;


//struct a{
//	int s;
//	string n;
//}b[100];
//bool cmp(a x,a y){
//	if(x.s==y.s) return x.n<y.n;
//	else return x.s>y.s;
//}


