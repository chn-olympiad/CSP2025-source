#include <bits/stdc++.h>
using namespace std;
bool f=0;
int n,m;
int sr[110];
int a[15][15];
int c,b;
int cmp(int a,int b){
	return a>b;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>sr[i];
	}
	c=sr[1];
	sort(sr,sr+n*m,cmp);
	/*for(int i=1;i<=n*m;i++){
		if(sr[i]==c){
			b=i;
		}
	}
	int g=b/n,h=b%n;                                                                                             
	if(g%2==0){
		<<g+1<<" "<<h+1;
	}else{
		cout<<g+1<<" "<<n-h+1;
	}
    */for(int i=0;i<n;i++){                                      
		if(f==0){
			for(int j=0;j<m;j++){
				a[i][j]=sr[i*m+j];
			}
		}else{
			for(int j=m;j>=0;j--){
				a[i][j]=sr[i*m+j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==c){
				cout<<i+1<<" "<<j+1;
			}
		}
	}//求你了，多给点分
    return;
    }
