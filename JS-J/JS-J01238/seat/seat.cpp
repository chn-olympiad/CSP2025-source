#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nn=n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int cntcnt=cnt,aa=0;
	for(;cnt>=n;){
		aa++;
		cnt=cnt-nn;
	}
	cnt=cntcnt;
	int lie=aa+1,hang;
	if(lie%2==0){
		hang=n-(cnt-(lie-1)*n);
	}else{
		hang=(cnt-(lie-1)*n+1);
	}
	cout<<lie<<" "<<hang<<endl;
	return 0;
}
