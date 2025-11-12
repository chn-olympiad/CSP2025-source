#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int jie=a[1];
	sort(a+1,a+1+n*m,cmp);
	int han=1,lei=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==jie){
			cout<<lei<<" "<<han<<endl;
			return 0;
		}
		if(lei%2){
			han++;
			if(han>n){
				han=n;
				lei++;
			}
		}
		else{
			han--;
			if(han<1){
				han=1;
				lei++;
			}
		}
	}
}
