#include<bits/stdc++.h>
using namespace std;

int n,m,r=1,c=1,dir=1;

struct node{
	int res;
	bool flag=false;
}stu[105];

bool cmp(node a,node b){
	return a.res>b.res;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].res;
	}
	stu[1].flag=true;
	sort(stu+1,stu+(n*m)+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(stu[i].flag==true){
			cout<<c<<" "<<r;
			break;
		}
		if(i%n==0){
			c++;
			dir=(-dir);
			continue;
		}
		r+=dir;
	} 
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
