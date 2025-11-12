#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[19][19],h=1,cnt=1;
int s[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>s[i];
	}
	int p=s[1];
	sort(s,s+k+1);
	for(int i=1;i<=m;i++){
		if(h<n){
			h=1;
			while(h<=n){
			a[h][i]=s[k--];
			
			
			h++;
		}
		}else{
			h=n;
			while(h>0){
			a[h][i]=s[k--];
			h--;
		}
	}
}
	for(int i=1;i<=n;i++){
		for(int h=1;h<=m;h++){
			
		if(a[i][h]==p){
			cout<<h<<' '<<i;
			return 0;
		}
		}
		
	}

	return 0;
}
