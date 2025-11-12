#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int t,n,ans,tp;
int a1[N],a2[N],a3[N],b[N],c[N];
void kun(int pos,int l){
//	cout<<pos;
	int k=0;
	for(int i=1;i<=n;i++){
		if(b[i]==pos){
			if(pos==1){
				k++;
				if(tp==n){
					c[k]=a1[i]-a2[i];
				}else{
					c[k]=min( (a1[i]-a2[i]) , (a1[i]-a3[i]) );
				}
				
			}else if(pos==2){
				k++;
				c[k]=min( (a2[i]-a1[i]) , (a2[i]-a3[i]) );
			}else if(pos==3){
				k++;
				c[k]=min( (a3[i]-a1[i]) , (a3[i]-a2[i]) );
			}
		}
	}
//	cout<<"***"<<pos<<"**"<<endl;
//	cout<<k;
	sort(c+1,c+k+1);
	for(int i=1;i<=k;i++){
//		cout<<c[i]<<" ";
		if(i<=l){
			ans-=c[i];
		}
		c[i]=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		tp=0;
		int n2=n/2,x=0,y=0,z=0;
//		cout<<n2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a3[i]==0) tp++;
			int ma=max(a1[i],max(a2[i],a3[i]));
			if(ma==a2[i]) y++,b[i]=2;
			if(ma==a1[i]) x++,b[i]=1;
			if(ma==a3[i]) z++,b[i]=3;
			ans+=ma;
//			cout<<ma<<" "<<b[i]<<endl;
		}
//		cout<<x<<" "<<y<<" "<<z;
		if(x>n2){
			kun(1,x-n2);	
		}else if(y>n2){
			kun(2,y-n2);
		}else if(z>n2){
			kun(3,z-n2);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a1[i]=a2[i]=a3[i]=b[i]=0;
		}
		ans=0;
	}
	
	return 0;
}
/*
Ren5Jie4Di4Ling5%
4             2
4 2 1
3 2 4
5 3 4
3 5 1

4 4 5 5
1 3 1 2

5/2==2  3 1 1
*/
