#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	int a[n+1][m+1]={};
	vector<int>b;
	int y;
	for(int i=1;i<=n*m;i++){
		cin>>y;
		if(i==1){
			s=y;
		}
		b.push_back(y);
	}
	sort(b.begin(),b.end());
	int d=0,xx=0,yy=1,v=0;
	for(int x=b.size()-1;x>=0;x--){
		if(d==0){
			xx++;
			a[xx][yy]=b[x];
			v++;
			if(b[x]==s){
				cout<<yy<<" "<<xx;
			}
		}else{
			if(d==1){
				xx--;
				a[xx][yy]=b[x];
				v++;
				if(b[x]==s){
				cout<<yy<<" "<<xx;
			}
			}
		}
		if(v==n){
			v=0;
			yy++;
			if(d==0){
				d=1;
				xx++;
			}else{
				if(d==1){
					d=0;
					xx--;
				}
			}
		}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
