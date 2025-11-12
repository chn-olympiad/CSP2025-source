#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int a[N];
	for(int i=0;i<N;i++){
		a[i]=-1;
	}
	for(int i=0;i<n.size();i++){
		if(n[i]>=48&&n[i]<=57){
			a[i]=int(n[i])-48; 
		}
	}
	sort(a,a+N);
	for(int i=N-1;i>=0;i--){
		if(a[i]==-1){
			break;
		}
		cout<<a[i];
	}
	return 0;
}
