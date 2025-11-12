#include<bits/stdc++.h>
using namespace std;

struct node{
	int id,sc;
}a[110];

bool cmp(node a,node b){
	return a.sc>b.sc;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		if(i==1){
			a[i].id=2;
		}else{
			a[i].id=1;
		}
	}
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].sc<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
//				cout<<a[cnt].sc<<" ";
				if(a[cnt].id==2){
					cout<<i<<" "<<j<<"\n";
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
//				cout<<a[cnt].sc<<" ";
				if(a[cnt].id==2){
					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		
	}
	return 0;
}
