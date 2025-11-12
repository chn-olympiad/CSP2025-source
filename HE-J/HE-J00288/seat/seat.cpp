#include<bits/stdc++.h>
using namespace std;
int s[11][11];
int a[103];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int n,m,r;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+2,cmp);
	
	int n1=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1){
				s[j][i]=a[n1];
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=m;j++){
//						cout<<s[i][j]<<" ";
//					}
//					cout<<endl;
//				}
//				cout<<endl;	
			}else{
				s[n-j+1][i]=a[n1];
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=m;j++){
//						cout<<s[i][j]<<" ";
//					}
//					cout<<endl;
//				}
//				cout<<endl;	   
			}
			//cout<<"n1:"<<a[n1]<<" ";
			n1++;
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	
}

