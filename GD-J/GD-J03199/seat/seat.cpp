#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int w,id;
}a[1050];
bool cmp(node a,node b){
	return a.w>b.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp); 
	int l=1,h=1;
	bool f=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<l<<' '<<h;
			break; 
		}
		cout<<l<<' '<<h<<"\n";
		if(h==n||h==1&&l!=1){
			if(!f) l++,f=1;
			else{
				f=0;
				if(l&1) h++;
				else h--;
			}
		}
		else{
			if(l&1) h++;
			else h--;
		}
	} 
	return 0;
}


