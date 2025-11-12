#include<bits/stdc++.h>
using namespace std;
int n,a[100010][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=0;
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])f=1;
		}
		if(!f){
			bool f1=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[j+1][1]>=a[j][1]){
						swap(a[j][1],a[j+1][1]);
						f1=1;
					}
				}
				if(!f1)break;
			}
			int s=0;
			for(int i=1;i<=n;i++)
				s+=a[i][1];
			cout<<s;
		}
	}
	return 0;
}
