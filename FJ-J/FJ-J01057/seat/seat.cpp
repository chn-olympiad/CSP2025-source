#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,a[1005],b[1005],R;
int cmp(int x,int y){
	return x>y;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=1,r=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i],b[i]=a[i],R=a[1];
		if(n+m==2)cout<<a[i];
	}	
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<b[i]<<" ";
		if(b[i]==R){
//			cout<<endl<<i<<" ";	
//			3 3 94 95 96 97 98 99 100 93 92
			if(m>=i){
				cout<<c<<" "<<i;
				return 0;
			}
			else if(m>i){
				for(int j=1;j<=m;j++){
					if(m<i){
						c++;
						i-=m;
						if(m>i){
							if(c%2==0){
								r=m-i;
								if(r==0)r=1;
							}
							else if(c%2!=0){
								r=i;
							}
						}
						
					} 
//					c++,r=m-i;
//					if(r<=m){
//						if(r==0){cout<<c<<" "<<1;break;}
//						else {cout<<c<<" "<<r;break;}
//					}
//					else if(r>m){
//						i-=m;
//						c++,r=i;
//						if(r>m)continue;
//						else if(r<=m){
//							cout<<c<<" "<<r;
//							break;
//						}
//					}
				}
			}
		}
	}
	cout<<c<<" "<<r;	
	return 0;
} 



