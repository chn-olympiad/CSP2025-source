#include<bits/stdc++.h>
using namespace std;
struct stu{
	int data;
	int id;
};
stu sz[105], sz1[11][11];
bool cmp(stu s1,stu s2){
	return s1.data>s2.data;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int i, j, n, m, w, x, y, t=0;
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>sz[i].data;
		sz[i].id=i;
	}
	sort(sz,sz+n*m,cmp);
	for(i=0;i<n;i++){
		if(i%2==0){
			for(j=0;j<n;j++){
				sz1[j][i]=sz[t++];
			}
		}else{
			for(j=n-1;j>=0;j--){
				sz1[j][i]=sz[t++];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
//			cout<<sz1[i][j].data<<' ';
			if(sz1[i][j].id==0){
				x=i+1;
				y=j+1;
				break;
			}
		}
		if(j!=m){
			break;
		}
//		cout<<'\n';
	}
	cout<<y<<' '<<x;
	return 0;
}
