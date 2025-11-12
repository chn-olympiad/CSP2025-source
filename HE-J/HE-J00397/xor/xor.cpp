#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans;
struct node{
	int l,r,chong,ji;
}b[500005];
int h;
int zhao(){
	for(int i=1;i<=h;i++){
		b[i].ji=0;
	}
	for(int i=1;i<=h;i++){
		for(int j=i+1;j<=h;j++){
			if(i!=j){
				if(!b[i].ji&&!b[j].ji&&(b[i].l<=b[j].r&&b[i].r>b[i].l)){
					b[i].chong++;
					b[j].chong++;
				}
			}
		}
	}
	int ma=0;
	for(int i=1;i<=h;i++){
		ma=max(ma,b[i].chong);
	}
	for(int i=1;i<=h;i++){
		if(b[i].chong==ma){
			b[i].ji=1;
		}
	}
}
bool pan(){
	for(int i=1;i<=h;i++){
		for(int j=i+1;j<=h;j++){
			if(i!=j){
				if(!b[i].ji&&!b[j].ji&&(b[i].l<=b[j].r||b[i].r>=b[j].l)){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int y=a[i];
			if(i==j){
				y=a[i];
			}
			else{
				for(int k=i+1;k<=j;k++){
					y=y^a[k];
				}
			}
			if(y==m){
				b[++h].l=i;
				b[h].r=j;
			}
		}
	}

	while(pan()){
		zhao();
	}
	for(int i=1;i<=h;i++){
		if(!b[i].ji){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
