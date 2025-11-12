#include <bits/stdc++.h>
using namespace std;
int n,m,mp[11][11];
struct f{
	int bh,fs;
}a[101];
bool cmp(f a,f b){
	return a.fs>b.fs;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	bool h=0,u=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].bh=i;
		if(a[i].fs!=i)h=1;
		if(a[i].fs!=n*m-i+1)u=1;
	}
	if(u==0){
		cout<<1<<" "<<1<<"\n";
		return 0;
	}
	if(h==0){
		if(m%2==0){
			cout<<1<<" "<<m;
		}else{
			cout<<n<<" "<<m;
		}
		return 0;
	}
	sort(a+1,a+1+n*m,cmp); 
	bool flag=0;	
	for(int i=1,k=1;i<=m,k<=n*m;i++){
		if(flag==0){
			for(int j=1;j<=n;j++){
				if(a[k].bh==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				mp[i][j]=a[k].fs;
				k++;
			}
			flag=1;
		}else if(flag==1){
			for(int j=n;j>=1;j--){
				if(a[k].bh==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				mp[i][j]=a[k].fs;
				k++;
			}
			flag=0;
		}
		
	}
	return 0;
}
