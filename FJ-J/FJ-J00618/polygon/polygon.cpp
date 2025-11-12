#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,t=0,m,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=2;
	while(l<=4999){
		for(int i=1;i<=n-l;i++){
			for(int j=i;j<=i+l-1;j++){
				t+=a[j];
				m=a[i+l];
			}
			if(t>m)
			s++;
			else
			continue;	
		}
		l++;
	}
	cout<<s;
	return 0;
}