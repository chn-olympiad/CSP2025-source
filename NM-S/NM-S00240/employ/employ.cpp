#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],b,c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
//wobuhuile(qwq);
		cin>>a[i];
		if(a[i]==1){
			b++;
		}
	}
	for(int i=0;i<n;i++){
//pianfening(qvq);
		cin>>c[i];
	}
	cout<<b;
	return 0;
}
//haoxiangmeipiancheng(q^q);
