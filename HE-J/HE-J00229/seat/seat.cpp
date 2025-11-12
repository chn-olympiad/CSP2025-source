#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m; 
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+c+1);
	int x=1,y=1;
	for(int i=c;i>=1;i--){
		if(a[i]==s){
			cout<<y<<" "<<x;
		}
		if(x==m&&y%2!=0){
			y++;
		}else if(x==1&&y!=1){
			y++;
		}else{
			if(y%2==0){
				x--;
			}else{
				x++;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

