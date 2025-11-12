#include<bits/stdc++.h>
using namespace std;
int n,m,mb;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	mb=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==mb){
			if((i/m)%2==0){
				cout<<i/m+1<<" "<<i%m+1;
			}else{
				cout<<i/m+1<<" "<<m-i%m;
			}
			return 0;
		}
	}
	return 0;
}
