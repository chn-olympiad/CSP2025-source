#include<bits/stdc++.h>
using namespace std;
int n,m,v,a[101],cnt=0,flag=0,fl=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=0;i<n*m-1;i++){
		int t=0;
		cin>>t;
		a[t]++;
	}
	for(int i=100;i>v;i--){
		if(i!=0){
			for(int j=0;j<a[i];j++){
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		fl++;
		if(fl%2==1){
			for(int j=1;j<=n;j++){
				if(cnt==0){
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
				cnt--;
			}
		}else if(fl%2==0){
			for(int j=n;j>=1;j--){
				if(cnt==0){
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
				cnt--;				
			} 
		}
		if(flag==1){
			break;
		}
	}
	return 0;
}
