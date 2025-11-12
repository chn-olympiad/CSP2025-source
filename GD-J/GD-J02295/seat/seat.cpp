#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out,","w",stdout);
	int R,n,m,cnt=0;
	cin>>n>>m;
	int q[n*m];
	cin>>R;
	q[0]=R;
	for(int i=1;i<n*m;i++) cin>>q[i];
	sort(q,q+n*m,cmp);
	int s[n][m];
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				s[j][i]=q[cnt];
				cnt++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				s[j][i]=q[cnt];
				cnt++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]==R) cout<<j+1<<" "<<i+1;
		}
	}
	return 0;
}
