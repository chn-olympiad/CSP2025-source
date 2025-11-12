#include<bits/stdc++.h>
using namespace std;
int s[10];
int c[10];
int main(){
	freopen("employ .in","r",stdin);
	freopen("employ .out","w",stdout);
	int n,m;
	int a=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>c[i];
		if(c[i-2]>=1){
			a++;
			if(c[i-1]>=c[i-2]){
				a++;
				if(c[i]>=c[i-1]+c[i-2]){
					a++;
				}
			}
		}
		if(a=m&&a>m){
			cout<<m;
		}else{
			cout<<a;
		}
	}
	return 0;
}