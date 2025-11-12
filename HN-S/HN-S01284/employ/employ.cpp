#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int c[MAXN];
long long fic1(int m){
	if(m==0) return 1;
	if(m==1) return 1;
	else return fic1(m-1)*m;
}
long long fic2(int m,int n){
	return fic1(n)/(fic1(n-m)*fic1(m));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long sum=0;
	for(int i=m;i<=n;i++){
		int a=fic2(i,n);
		sum+=a;
	}
	cout<<sum;
	return 0;
}
