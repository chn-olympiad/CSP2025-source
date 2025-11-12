#include<bits/stdc++.h>
using namespace std;

struct st{
	int name;
	int grade;
};
st a[1005];
bool cmp(st a,st b){
	return a.grade>b.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[0].name=1;
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i].grade);
	}
	sort(a,a+n*m,cmp);
	int z=0;
	while(a[z].name!=1) ++z;
	int l=z/n+1;
	if(l%2==1){
		cout<<l<<' '<<z%n+1;
		return 0;
	}
	cout<<l<<' '<<n-(z%n);
	return 0;
}





