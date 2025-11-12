#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],s,x;
string c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n;i++){
		if(c[i]==1){
			if(x<=a[i])s++;
		}else{
			x++;
		}
	}
	if(m==1){
		cout<<s;
	}
	return 0;
}
