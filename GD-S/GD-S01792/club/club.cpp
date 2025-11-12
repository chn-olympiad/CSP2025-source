#include<bits/stdc++.h>
using namespace std;
int t,n,s=0;
struct x{
	int x1;
	int x2;
	int x3;
}a[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].x1>>a[j].x2>>a[j].x3;
			s+=max(a[j].x1,max(a[j].x2,a[j].x3));
		}
		cout<<s;
	}
	
	return 0;
} 
