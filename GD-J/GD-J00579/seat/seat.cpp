#include<bits/stdc++.h>
using namespace std;
struct f{
	int x,y;
}b[105];
int cmp(f w,f q){
	return w.x>q.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;int ant;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].x;
		if(i==1){
			ant=b[i].x;
		}
		b[i].y=i;
	}sort(b+1,b+1+n*m,cmp);
	
	for(int i=1;i<=n*m;i++){
		
		if(b[i].x==ant){
			ant=i;
			
		}
	}
	
	int c,r;
	if(ant%n==0){
		c=ant/n;
		if(ant/n%2==1){
			r=n;
		}else if(ant/n%2==0){
			r=1;
		}
	}else{
		c=ant/n+1;
		if((ant/n+1)%2==1){
			r=ant-ant/n*n;
		}else if((ant/n+1)%2==0){
			r=n-(ant-ant/n*n)+1;
			
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
