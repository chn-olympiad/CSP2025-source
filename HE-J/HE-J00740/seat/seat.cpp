#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[110],a2[110],b[20][20],cnt=1,score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a2[i];
	score=a2[1];
	sort(a2+1,a2+n*m+1);
	for(int i=n*m; i>=1; i--) a[n*m-i+1]=a2[i];
	
	for(int i=1; i<=m; i++){
		if(i%2==0)
			for(int j=n; j>=1; j--){
				b[j][i]=a[cnt];
				cnt++;
			}
		else
			for(int j=1; j<=n; j++){
				b[j][i]=a[cnt];
				cnt++;
			}
	}
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(b[j][i]==score){
				cout<<i<<" "<<j;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
