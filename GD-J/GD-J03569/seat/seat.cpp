#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100001];
	int k=0;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		k=a[1];
	}
	int s=1;
	int j=1;
	for(int i=1;i<=n*m;i++){
		if(k<a[i]){
			if(j<n&&s%2==1){
				j++;
			}
			else if(j==n&&s%2==1){
				s++;
			}
			else if(j>1&&s%2==0){
				j--;
			}
			else if(j==1&&s%2==0){
				s++;
			}
		}
	}
	cout<<s<<' '<<j;
} 
