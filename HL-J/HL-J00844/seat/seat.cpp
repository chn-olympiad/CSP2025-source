#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	/**/int n,m,rr=0,cnt=1;
	/**/bool f[105]={false};
	cin >>n>>m;
	/**/int a[n+5][m+5]={0},b[n*m+5]={0};
	cin >> b[1];
	f[b[1]]=true;
	for(int i=2;i<=n*m;i++){
		cin >>b[i];	
		cnt++;
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
				a[i][j]=b[cnt];
				cnt--;	
		}
	}
	int cnt1=0;
	for(int i=2;i<=m;i+=2){
		int t[n+5]={0};
		for(int j=1;j<=n;j++){
			t[j]=a[i][j];
			cnt1++;
		}
		sort(t+1,t+cnt1);
		int jj=1;
		for(int j=n;j>=1;j--){
			a[i][jj]=t[j];	
			jj++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[a[j][i]]==true)cout <<j<<" "<<i<<endl;
		}
	}
	return 0;
}

