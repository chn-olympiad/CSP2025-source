#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long awa[110];
long long a[20][20];
long long ovo;
long long cnt;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>awa[i];
	}
	cnt=awa[1];
	sort(awa+1,awa+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ovo++;
				a[j][i]=awa[ovo];
				if(awa[ovo]==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ovo++;
				a[j][i]=awa[ovo];
				if(awa[ovo]==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
