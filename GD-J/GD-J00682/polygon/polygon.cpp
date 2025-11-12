#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
long long n,a[5010]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	cout<<n*(n-1)*(n-2)/(2*3);
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


