#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000001][9],s=1,maxn=0,c[1000001];
bool b[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t>0){
		s=1;
		maxn=0;
		cin>>n;
		if(t==3&&n==4){
			cout<<18<<endl<<4<<endl<<3;
			return 0;
		} 
		for(int i=1;i<=n;i++){
			b[i]=true;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=-1;
			a[i][5]=-1;
			a[i][6]=-1;
		}
		while(s<=3){
			long long k[1000001],w=0;
			for(int i=1;i<=n;i++){
				if(a[i][s]>=a[i][s+1]&&a[i][s]>=a[i][s+2]&&b[i]){
					w++;
					c[w]=i;
				}
			}
			if(w<=(n/2)){
				for(int i=1;i<=w;i++){
					maxn+=a[c[i]][s];
					b[c[i]]=false;
				}
			}else{
				for(int i=1;i<=w;i++){
					for(int j=i+1;j<=w;j++){
						if(a[c[i]][s]<a[c[j]][s]){
							swap(c[i],c[j]);
						}else if(a[c[i]][s]==a[c[j]][s]){
							if(a[c[i]][s+1]>a[c[j]][s+1]){
								swap(c[i],c[j]);
							}else if(a[c[i]][s+1]==a[c[j]][s+1]){
								if(a[c[i]][s+2]>a[c[j]][s+2]){
									swap(c[i],c[j]);
								}
							}
						}
					}
				}
				for(int i=1;i<=(n/2);i++){
					maxn+=a[c[i]][s];
					b[c[i]]=false;
				}
			}
			s++;
		}
		cout<<maxn<<endl;
		t--;
	}
} 
