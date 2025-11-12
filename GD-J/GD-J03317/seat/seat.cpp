#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct edge{
	int pos,num;
}a[110];
bool cmp(edge x,edge y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].pos=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].pos==1){
			int ni;
			if(i%n==0) ni=(i-1)/n+1;
			else ni=i/n+1;
			cout<<ni<<" ";
			if(ni%2==0){
				cout<<(m+1)-((i-1)%n+1)<<endl;
			}else{
				cout<<(i-1)%n+1<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


