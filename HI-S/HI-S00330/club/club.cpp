#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],m,maxx,minn,b[100005],c=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		bool bo=0;
		for(int k=1;k<=n;k++){
			cin>>a[k][1]>>a[k][2]>>a[k][3];
			if(a[k][2]!=0||a[k][3]!=0){
				bo=1;
			}
		}
		if(bo==0){
			for(int k=1;k<=n;k++){
			if(m<(n/2)){
				maxx+=a[k][1];
				b[c]=a[k][1];
				sort(b-1,b+c-1);
				c++;
				m++;
			}
			else{
				if(a[k][1]>b[0]){
					maxx=maxx-b[0]+a[k][1];
					b[c]=a[k][1];
					sort(b-1,b+c-1);
					c++;
				}
			}
		}
		}
		
		cout<<maxx;
		maxx=0;
		
	}
	return 0;
}
