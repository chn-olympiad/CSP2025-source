#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
		}
		int mx1=-1,mx2=-1,mx3=-1;
		for(int i=1;i<=n;i++){
			if(mx1<a[i][1])mx1=a[i][1];
		}for(int i=1;i<=n;i++){
			if(mx2<a[i][2]&&mx1==a[i][1]){
				if(a[i][2]<mx1)a[i][2]=-1;
				else {
					int mxx1=-1;
					for(int j=1;j<=n;j++){
						if(mxx1<a[j][1]&&j!=i)mxx1=a[j][1];
					}
					mx1=mxx1;
				}
			}
			else if(mx2<a[i][2])mx2=a[i][2];
		}for(int i=1;i<=n;i++){
			if(mx3<a[i][3]&&mx1==a[i][3]){
				if(a[i][3]<mx1||a[i][3]<mx2)a[i][3]=-1;
				else{
					int mxx1=-1,p;
					for(int j=1;j<=n;i++){
						if(mxx1<a[j][1]&&j!=i){mxx1=a[j][1];p=j;}
					}
					mx1=mxx1;
					int mxx2=-1;
					for(int j=1;j<=n;i++){
						if(mxx2<a[j][1]&&j!=i&&j==i){
							if(a[i][3]<mx2)a[i][3]=-1;
								else {
									int mxx2=-1;
									for(int j=1;j<=n;j++){
										if(mxx2<a[j][1]&&j!=i)mxx2=a[j][2];
									}
									mx2=mxx2;
								}
						}
						else{
							int mxx3=-1;
							if(mxx3<a[j][1]&&j!=i){
								maxx3=a[j][i];
							}
						mx3=mxx3;
				}
			}
		}
	}
			else if(mx3<a[i][3])mx3=a[i][3];
	}
		cout<<mx1+mx2+mx3<<endl;
}
	return 0;
}
