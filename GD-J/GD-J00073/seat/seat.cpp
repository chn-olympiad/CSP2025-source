#include<bits/stdc++.h> 
using namespace std;
int n,m,c=1,r=1,x,fx=1;
struct chengji{
	int s;
};
bool cmp(chengji x,chengji y){
	return x.s>y.s; 
}
int main(){
	chengji a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		if(i==1)x=a[1].s;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].s==x){
			cout<<c<<" "<<r;
			return 0;
		}else{
			if(fx==1){
				r++;
				if(r>n){
					fx=2;
					r=n;
					c++;
				} 	
			}else{
				r--;
				if(r==0){
					fx=1;
					r=1;
					c++;
				} 
			}
			
		}
	}
	return 0;
}
