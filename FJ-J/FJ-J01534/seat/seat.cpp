#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,f,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l++;
			if(a[l]==f){
				if(i%2==1){
					cout<<i<<" "<<j<<endl;
				}else{
					cout<<i<<" "<<m-j+1<<endl;
				}
				return 0;
			}
		}
	} 
	return 0;
}
