#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,gradess,a[10000],dx,dy;
	scanf("%d%d",&n,&m);
	x=n*m;
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i]);
	}gradess=a[1];
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==gradess){
		//	cout<<i<<endl;
			if(i%n!=0){
				dy=(i/n)+1;
			}else dy=i/n;
			if(dy%2!=0){
				dx=i%n;
				if(dx==0){
					dx=n;
				}
			}else{
				dx=n+1-(i%n);
				if(dx>n)dx=1;
			}
			break;
		}
	}
	cout<<dy<<" "<<dx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
