#include<bits/stdc++.h>
using namespace std;


int m,n,a[105];
int ans[105][105];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=a[1];
	sort(a+1,a+1+n*m,cmp);
	int num;
	for(int i=1;i<=n*m;i++)
		if(a[i]==b){
			num=i;
			break;
		}
		
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(num==(i-1)*n+j){
					cout<<i<<" "<<j;
					break;
				}
			}	
		}
		else{
			for(int j=1;j<=n;j++){
				if(num==(n*i-j+1)){
					cout<<i<<" "<<j;
					break;
				}
				
			}	
		}
	}
	fclose(stdout);
	return 0;
} 