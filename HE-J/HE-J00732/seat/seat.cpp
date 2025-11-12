#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],nm,tot;
bool cmp(int x,int y){
	return x>y;
}
bool amp(int x,int y){
	return x<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	nm=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(a[i*n]<=nm){
			if(i%2==1){
				sort(a+(i-1)*n+1,a+i*n+1,cmp);
				for(int j=(i-1)*n+1;j<=i*n+1;j++){
					tot++;
					if(a[j]==nm){
						cout<<i<<" "<<tot;
						return 0; 
					}
				}
			}
			else{
				sort(a+(i-1)*n+1,a+i*n+1,amp);
				for(int j=(i-1)*n+1;j<=i*n+1;j++){
					tot++;
					if(a[j]==nm){
						cout<<i<<" "<<tot;
						return 0; 
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
