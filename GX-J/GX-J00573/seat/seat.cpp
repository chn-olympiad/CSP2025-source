#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int num;
	int grade;
}a[120];
int pai;
bool cmp(node x,node y){
	return x.grade>y.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	pai=n*m;
	for(int i=1;i<=pai;i++){
		cin>>a[i].grade;
		a[i].num=i;
	}
	sort(a+1,a+pai+1,cmp);
	int cnt;
	for(int i=1;i<=pai;i++){
		if(a[i].num==1){
			cnt=i;
			break;
		}
	}
	int lie;
	if(cnt%n==0){
		lie=cnt/n;//head or tail
		if(lie%2==0){
			cout<<lie<<" "<<1;
			return 0;
		}else{
			cout<<lie<<" "<<n;
		}
	}else{
		lie=cnt/n+1;
		int date=cnt-(lie-1)*n;
		if(lie%2==0){
			int hang=n-date+1;
			cout<<lie<<" "<<hang;
			return 0;
		}else{
			cout<<lie<<" "<<date;
			return 0;
		}
	}
	return 0;
}
