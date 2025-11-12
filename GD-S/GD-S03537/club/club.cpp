#include<bits/stdc++.h>

using namespace std;
struct Node{
	int id;
	int h;
};
int fs(int a,int b,int c){
	if(a>b){
		if(c>a) return c-a;
		if(b>c) return a-b;
		else return a-c;
	}
	else{
		if(c>b) return c-b;
		if(a>c) return b-a;
		else return b-c;
	}
}
bool cmp(vector<int> x,vector<int> y){
	return fs(x[0],x[1],x[2])>fs(y[0],y[1],y[2]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		vector<vector<int> >a(n+5,vector<int>(3,0)) ;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		sort(a.begin(),a.begin()+n,cmp);
		vector<int> cnt(3,0);
		int i=0;
		while(i<n){
			int x=a[i][0],y=a[i][1],z=a[i][2];
			if(x>y){
				if(z>x){
					if(cnt[2]!=n/2){
						ans+=z;
						cnt[2]++;
					}
					else{
						ans+=x;
					}
				} 
				else {
					if(cnt[0]!=n/2){
						ans+=x;
						cnt[0]++;		
					}
					else{
						if(y>z) ans+=y;
						else ans+=z;
					}
				}
			}
			else{
				if(z>y) {
					if(cnt[2]!=n/2){
						ans+=z;
						cnt[2]++;
					}
					else{
						ans+=y;
					}
				}
				else {
					if(cnt[1]!=n/2){
						ans+=y;
						cnt[1]++;		
					}
					else{
						if(x>z) ans+=x;
						else ans+=z;
					}
				}
			}
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
