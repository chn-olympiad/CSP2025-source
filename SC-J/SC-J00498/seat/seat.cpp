#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int b){
	if(x>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],b,s=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			b=i;
			//cout<<b<<endl;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s++;
				if(b==s){
					cout<<i<<' '<<j;
					break;
				}
				
			}
		}else{
			for(int j=n;j>=1;j--){
				s++;
				if(b==s){
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
}