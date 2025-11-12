//GZ-S00077 卿馨元 华东师范大学附属贵阳学校
#include<bits/stdc++.h> 
using namespace std;
int k;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	for(int i=1;i<=k;i++){
		int n,t;
		cin>>n;
		int a[n+5],b[n+5],c[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			t+=b[i]*c[i];
		}
		cout<<t/2;
	}
	return 0;
}
