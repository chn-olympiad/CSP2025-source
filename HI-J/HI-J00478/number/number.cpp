#include<bits/stdc++.h>
using namespace std;
//const int N_MAX=1e5+5;
int a[1001000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int u=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[u]=int(n[i]-'0');
			u++;
		}
	}
	/*for(int i=0;i<u;i++){
		for(int j=1;j<u;j++){
			if(a[j-1]<a[j]){
				int x=a[j-1];
				a[j-1]=a[j];
				a[j]=x;
			}
		}
	}*/
	sort(a,a+u);
	if(a[u-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=u-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

