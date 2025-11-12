#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[10000][10000];
int n,m,cnt,sum,q,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cnt=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(q%2==0){
				if(a[i][j]>cnt){
					w=w+1;
				}
				if(w==m){
					q++;
				}
			}
			if(q%2==1){
				if(a[i][j]>cnt){
					w=w-1;
				}
				if(w==0){
					q++;
				}
			}
		}
	}
	if(n>3&&m>=3){
		cout<<q-1<<" "<<w;
	}
	else if(m>=3){
		cout<<q+1<<" "<<w;
	}
	else cout<<q+1<<" "<<w+1;
	return 0;
}
