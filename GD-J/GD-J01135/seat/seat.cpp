#include<bits/stdc++.h>
using namespace std;
int ji[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R,sum=0;
	cin>>R;
	for(int i=1;i<=n*m-1;i++){
		scanf("%d",&ji[i]);
		if(ji[i]>R)sum++;
	}
	if(sum==0)cout<<1<<' '<<1;
	int lie,hang;
	lie=(sum/m)+1;
	int qm=sum%n+1;
	if(lie%2==1){
		hang=qm;
	}else{
		hang=n-qm+1;
	}
	cout<<lie<<' '<<hang;
	return 0;
} 
