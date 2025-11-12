#include<bits/stdc++.h> 
using namespace std;//9.12
#define elif else if
struct node{
	int v,id;
}a[111];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a,a+n*m,cmp);
	int nn=1,mm=0;
	for(int i = 0;i<n*m;i++){
		if(nn==n){
			if(mm%2==1){
				mm++;
			}
			else{
				nn--;
			}
		}
		elif(nn==1 && mm%2==0){
			mm++;
		}
		elif(mm%2 == 1){
			nn++;
		}
		else{
			nn--;
		}
//		cout<<mm<<" "<<nn<<endl;
		if(a[i].id==0){
			cout<<mm<<" "<<nn;
			return 0;
		}
	}
	return 0;
}
