#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int a[N][N];
int x,y,n,m;
struct Node{
	int id,grade;
}node[2005];


bool cmp(Node Z , Node X){
	return Z.grade>X.grade;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	cin>>m;

	for(int i=1;i<=n*m;i++){
		cin>>node[i].grade;
		node[i].id=i;
	}
	int num=1;
//	cout<<n*m<<endl; 
	sort(node+1,node+n*m+1,cmp);
//for(int i=1;i<=n*m;i++){
//		cout<<node[i].id<<" "<<node[i].grade<<endl;
//	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
		//	cout<<num<<" "<<j<<" "<<i<<" "<<node[num].id<<" "<<node[num].grade<<endl;
			if(node[num].id==1){
				
				if(j%2==0){
		//			cout<<"...";
					 x=j;
					 y=n-i+1;
				//	 cout<<x<<" "<<y<<endl;
				 } 
				else{
					x=j;
					y=i;
				}
				
			}
			num++;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
} 
