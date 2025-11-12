#include<iostream>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005] ={};
int map[1001][1001];
int vis[1001][1001];
int dx[3]={-1,0,1};
int dy[3]={0,-1,0};
int d=0;

int n,m;
bool cmp(int o1,int o2){
	if(o1!=o2){
		return o1>o2;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=0;
		}
	}
	int ff=0;
	int t=-1;
	int huan=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ff++;
			t++;
			map[i][j]=a[t];
			a[t]=-1;
			if(ff>n){
				huan++;
				if(huan%2!=0){
					sort(a,a+n*m);
					int fn=0;
					for(int i=1;i<=n*m;i++){
						if(a[i]==-1){
							fn++;
						}
					}
					t=fn;
					ff=0;
				}else{
					sort(a,a+n*m,cmp);
					huan++;
					t=-1;
					ff=0;
				}	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			} 
			
		}
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98

3 3
96 99 98 97 100 95 94 93 92 

*/
