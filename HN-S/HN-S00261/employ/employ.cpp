#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long ans;
struct s{
	int a1,a2,a3;
} a[N];
bool C(s u,s v){
	int a11=u.a1,a12=u.a2,a13=u.a3;
	int a21=v.a1,a22=v.a2,a23=v.a3;
	int maxx1=max(a11,max(a12,a13));
	int maxx2=max(a21,max(a22,a23));
	if(maxx1==maxx2){
		int maxxn1=(a11==maxx1?max(a12,a13):(a12==maxx1?max(a11,a13):max(a11,a12)));
		int maxxn2=(a21==maxx1?max(a22,a23):(a22==maxx1?max(a21,a23):max(a21,a22)));
		if(maxxn1==maxxn2){
			int n1=min(a11,min(a12,a13));
			int n2=min(a21,min(a22,a23));
			return n1>n2;
		}
		return maxxn1>maxxn2;
	}
	return maxx1>maxx2;
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,C);
		for(int i=1;i<=n;i++) cout<<a[i].a1<<' '<<a[i].a2<<' '<<a[i].a3<<endl;
	} 
	return 0;
}

