#include<bits/stdc++.h>
using namespace std;
int n,b[5],c[5],f;
struct aa{
	int a[5];
};
aa a[100005];
void cc(int x){
	if(x==n){
		int e=0;
		for(int i=1;i<=3;i++){
			e+=c[i];
		}
		if(e>f){
			f=e;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]<n/2){
			b[i]++;
			c[i]+=a[x].a[i];
			cc(x+1);
			c[i]-=a[x].a[i];
			b[i]--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		f=0;
		for(int i=1;i<=3;i++){
			c[i]=0;
			b[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].a[j];
			}
		}
		cc(0);
		cout<<f<<endl;
	}
	return 0;
} 
