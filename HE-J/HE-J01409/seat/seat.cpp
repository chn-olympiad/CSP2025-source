#include<bits/stdc++.h>
using namespace std;
int a[110];
int tot;
int ans=0;
int t=1;
int n,m;
bool cmp(int n,int m){
	return n>m;
}
void f(int m){//m:µÚ¼¸ÁÐ 
	if(m%2){
		for(int i=1;i<=n;i++){
			if(a[t]==tot){
				cout<<m<<" "<<i;
				ans=1;
				break;
			}else{
				t++;
			}
		}
	}else{
		for(int i=n;i>=1;i--){
			if(a[t]==tot){
				cout<<m<<" "<<i;
				ans=1;
				break;
			}else{
				t++;
			}
			
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) tot=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		f(i);
		if(ans) break;
	}
	return 0;
}
