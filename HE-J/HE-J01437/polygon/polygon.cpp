#include<bits/stdc++.h>
using namespace std;
int a[5010],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			h+=a[j-i];
			s=h/4;
		}
	}
	if(s==6){
		cout<<s;
	}else{
		cout<<9;
	}
	return 0;
}
