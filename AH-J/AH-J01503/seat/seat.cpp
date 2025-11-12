#include<bits/stdc++.h>
using namespace std;
int a[500];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,flag=0;
	int j=1,k=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<k<<" "<<j;
			return 0;
		}
		else{
			if(j<=n&&flag==0){
				if(j==n){
					k++;
					flag=1;
					continue;
				}
				j++;
			}
			else if(j>=1&&flag==1){
				if(j==1){
					k++;
					flag=0;
					continue;
				}
				j--;
			}
		}	
	}
	return 0;
}
