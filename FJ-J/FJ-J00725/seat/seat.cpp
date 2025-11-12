#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,id;
int a[N],st[N][N];

bool cmp(int a1,int a2){
	return a1>a2;
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	id=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	int h=1,l=1;
	for(int i=2;i<=n*m;i++){
		
		if(l%2==1){
			if(h==n)l++;
			else h++;
		}
		else{
			if(h==1)l++;
			else h--;
		}
		if(a[i]==id){
			cout<<l<<' '<<h;
			break;
		}
		//cout<<a[i]<<' '<<l<<' '<<h<<endl;
	}
	if(id==a[1])cout<<1<<' '<<1;
	return 0;
}/*
3 3
94 95 96 97 98 99 100 93 92
*/
