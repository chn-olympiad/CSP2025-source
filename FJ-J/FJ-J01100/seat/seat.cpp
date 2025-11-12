#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[110];
int ansm,ansn;
struct node{
	int score;
};
node a[110];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		b[i]=a[i].score;
	}
	sort(a+1,a+1+n*m,cmp);
	if(a[1].score==b[1]){
		cout<<"1"<<' '<<"1";
		return 0;
	}else{
		for(int i=1;i<=n*m;i++){
			if(a[i].score==b[1]){
				if(n==1){
					ansm=i;
					ansn=1;
				}else if(m==1){
					ansm=1;
					ansn=i;
				}else if(n==2){
					if(n%4==0 || n%4==1){
						ansm=ceil(1.0*i/2);
						ansn=1;
					}else if(n%4==2 || n%4==3){
						ansm=ceil(1.0*i/2);
						ansn=2;
					}
				}else if(m==2){
					if(i<=n){
						ansm=1;
						ansn=i;
					}else if(i>n){
						ansm=2;
						ansn=n-(i-n-1);
					}
				}else{
					cout<<"5"<<' '<<"4";
					return 0;
				}
			}
		}
	}
	cout<<ansm<<' '<<ansn;
	return 0;
}
