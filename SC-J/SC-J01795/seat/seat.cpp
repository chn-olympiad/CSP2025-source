#include<bits/stdc++.h>
using namespace std;
long long m,n,s[15][15];
struct st{
	long long a,b;
}stu[105];
bool cmp(st a,st b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].a;
		stu[i].b=i;
	}
	sort(stu+1,stu+1+n*m,cmp);
	long long x=1,y=1,z=0;
	while(1){
		++z;
		if(stu[z].b==1){
			cout<<y<<" "<<x;
			return 0;
		}
		for(int i=1;i<n;i++){
			x++;
			++z;
			if(stu[z].b==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		++z;
		y++;
		if(stu[z].b==1){
			cout<<y<<" "<<x;
			return 0;
		}
		for(int i=1;i<n;i++){
			++z;
			x--;
			if(stu[z].b==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		y++;
	}
	return 0;
} 