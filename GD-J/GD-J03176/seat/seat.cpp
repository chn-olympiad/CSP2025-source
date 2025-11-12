#include<bits/stdc++.h>
using namespace std;
int n,m,r,s[105],p,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;p=n*m;
	cin>>s[1],r=s[1];
	for(int i=2;i<=p;i++) scanf("%d",&s[i]);
	sort(s+1,s+p+1,greater<int>());
	for(int i=1;i<=p;i++){
//		cout<<s[i]<<' ';
		if(s[i]==r) w=i;
	}
//	cout<<endl<<w;
	int l=w/n,h=w%n;
//	cout<<l+1<<' ';
	if(h==0){
		cout<<l<<' ';
		if(l%2) cout<<n;
		else cout<<1;
	}
	else if((l+1)%2!=0){
		cout<<l+1<<' '<<h;		
	}
	else{
		cout<<l+1<<' '<<n-h+1;
	}

	return 0;
}
/*
2 2
98 99 100 97
*/
//9:23Completed
