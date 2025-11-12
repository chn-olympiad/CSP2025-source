#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans,x[30][N],lst=0x3f3f3f3f;
priority_queue<pair<int,int> >q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(!a[i]) ans++;
			else{
				if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
			else if(i!=n&&((a[i]==a[i+1]-1&&a[i]%2==0)||(a[i]==a[i+1]+1&&a[i]%2==1))){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}/*
	int y=1;
	for(int i=1;i<=n;i++) x[1][i]=i;
	for(int k=1;k<=log2(n)+1;k++){
		y*=2;
		for(int i=y;i<=n;i+=y){
			x[k][i]=x[k-1][i]^x[k-1][i+y/2];
		}
	}
	*/
	for(int i=2;i<=n;i++){
		int y=a[1];
		for(int j=2;j<i;j++) y^=a[j];
		//cout<<y<<" ";
		if(y==k) q.push({i-1,n-i+1});
		for(int j=i;j<=n;j++){
			y^=a[j-i+1];
			y^=a[j];
			if(y==k) q.push({j,n-i+1});
		}
	}
	while(q.size()){
		int lt=q.top().first,len=n-q.top().second;
		//cout<<lt<<" "<<lt-len+1<<endl;
		q.pop();
		if(lt<lst){
			ans++;
			lst=lt-len+1;
			//cout<<c<<" "<<d;
		}
	}
	cout<<ans;
	return 0;
}
