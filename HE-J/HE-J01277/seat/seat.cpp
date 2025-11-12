#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=110;
int a[N];
int s[20][20];
int r;
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int f=0;
	for(int j=1;j<=m;j++){//m列 
		if(j%2==1){
			for(int i=1;i<=n;i++){//n行 
				f++;
				s[i][j]=f; 
			}
		}else{
			for(int i=n;i>=1;i--){
				f++;
				s[i][j]=f;
			}
		} 
		
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<" ";
//		} 
//		cout<<endl;
//	}
	int pos=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pos=i;//记录是第几名 
		}
	}
	bool tt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==pos){
				cout<<j<<" "<<i<<endl;//先列再行 
				tt=1;
				break;
			}
		}
		if(tt==1) break;
	} 
	
	
	return 0;
}
