#include<bits/stdc++.h>
using namespace std;
long long n,m,b,t;
struct a{
	int score,zuo=0;
}a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].score;
		if(i==0){
			t=a[i].score;
		}
	}
	a[0].zuo=1;
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[i].score<a[j].score){
				swap(a[i],a[j]);
			}
		}
	}
//	for(int i=0;i<n*m;i++){
//		cout<<a[i].score<<" "<<a[i].zuo<<endl;
//	}
	for(int i=0;i<m*n;i++){
		if(a[i].zuo=1&&a[i].score==t){
//			cout<<i<<endl;
			b=i;
			break;
		}
	}
	a[b].zuo=b+1;
//	for(int i=0;i<n*m;i++){
//		cout<<a[i].score<<" "<<a[i].zuo<<endl;
//	}
	int d=a[b].zuo%(2*n);
	int c=a[b].zuo/(2*n),e=0;
	c*=2;
//	cout<<d<<" "<<c<<" "<<e<<" "<<a[b].zuo<<endl;
	if(d>n){
		c+=2;
		e=n-(d-n-1);
	}else if(d>0){
		c++;
		e=d;
	}else if(d==0){
		e=n;
	}
	cout<<c<<" "<<e;
	fclose(stdin);
	fclose(stdout);
} 
