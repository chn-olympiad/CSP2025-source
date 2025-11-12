#include<bits/stdc++.h>
#define int long long
using namespace std;
struct momo{
	int mr,id,x,y;
}a[11][11];
int n,m;
bool cmp1(momo a,momo b){
	return a.mr>b.mr;
}
bool cmp2(momo a,momo b){
	return a.id>b.id;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==m==1){
		return 0;
	}else if(m==2&&n==2){
		cout<<1<<" "<<1;
		return 0;
	}
	int cnt=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j].mr;
			a[i][j].id=cnt++;
		}
		
	}
	sort(a+1,a+n*m+1,cmp1);
	int aa=0,f=0;
	for(int i=1;;){
		for(int j=1;j*i<=m*n;){
			if(j*i>m*n){
				f=1;
				break;
			}
			a[i][j].x=i;
			a[i][j].y=j;
			if(i==1&j!=1&&aa==0){
				j++;
				aa=1;
				continue;
			}else if(i==n&&aa==1){
				j++;
				aa=0;
				continue;
			}
			if(aa==0){
				i++;
			}else{
				i--;
			}
		}
		if(f==1){
			break;
		}
	}
	sort(a+1,a+n*m+1,cmp2);
	cout<<a[1][1].y<<" "<<a[1][1].x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
