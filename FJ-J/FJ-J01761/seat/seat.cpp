#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r,R;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	R = a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == R){
			r = i%n;
			c = i/n;
			if(r == 0){
				r = n;
			}
			else{
				c++;
			}
			if(c%2==0){
				r = n+1-r;
			}
			printf("%d %d",c,r);
			return 0;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
