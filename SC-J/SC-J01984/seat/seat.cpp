#include<bits/stdc++.h>
using namespace std;
int n,m,b,c,d;
struct student{
	int num;
	int score;
}a[110];

int cmp(student x,student y){
	return x.score>y.score;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			b=i/n;
			c=i%n;
			if(b%2==0&&c==0){
				cout<<b<<" "<<c+1;
			}
			if(b%2==0&&c!=0){
				cout<<b+1<<" "<<c;
			}
			if(b%2==1&&c==1){
				cout<<b+1<<" "<<n;
			}
			if(b%2==1&&c!=1){
				cout<<b+1<<" "<<n-c;
			}
		}
	}
	

	return 0;
} 