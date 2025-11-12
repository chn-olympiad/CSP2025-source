#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],ans,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			cnt=i;
			break;
		}
	}
	int fx=0;//0:xia  1:shang
	long long x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(cnt==i){
			cout<<y<<" "<<x;
			return 0;;
		}
		if(fx==0){
			if(x==n){
				y++;
				fx=1;
			}else{
				x++;
			}
		}else{
			if(x==1){
				y++;
				fx=0;
			}else{
				x--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
