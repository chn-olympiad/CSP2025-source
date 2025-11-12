#include<bits/stdc++.h>
using namespace std;
int a[101],x,y,n,m,sum,seat;
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
	sum=a[1];
	int w=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			seat=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(w==seat){
					cout<<i<<" "<<j;
					return 0;
				}
				else{
					w++;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(w==seat){
					cout<<i<<" "<<j;
					return 0;
				}
				else{
					w++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
