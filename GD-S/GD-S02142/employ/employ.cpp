#include <bits/stdc++.h>
using namespace std;
string s;
int a[200005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int z=n;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			z--;
		}
	}
	cout<<z;
	return 0;
}
