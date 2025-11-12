#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int ach;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ach=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int hang,lie;
	for(int i=1;i<=m*n;i++){
		if(a[i]==ach){
			if(i%n==0){
				lie=i/n;
			}
			else{
				lie=(i/n)+1;
			}
			if(lie%2==1){
				if(i%n==0){
					hang=n;
				}
				else{
					hang=i%n;
				}
			}
			else{
				hang=n-(i%n)+1;
			}
			cout<<lie<<" "<<hang;
			return 0;
		}
	}
}
