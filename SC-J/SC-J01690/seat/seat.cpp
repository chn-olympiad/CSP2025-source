#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			int hang=i%n,lie=i/n;
			if(lie*n<i)lie++;
			if(lie%2==0){
				if(hang==0){
					hang++;
					cout<<lie<<" "<<hang;
					return 0;
				}
				hang=n-hang+1;
				cout<<lie<<" "<<hang;
				return 0;
			}
			else{
				if(hang==0)hang=n;
				cout<<lie<<" "<<hang<<endl;
			}
		}
	}
	return 0;
}
