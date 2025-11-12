#include<bits/stdc++.h>
using namespace std;
int d,n[100005],ans,b1,b2,b3,n1,n2,n3,c[100005];
struct node{
	int ma1;
	int ma2;
	int ma3;
}a[100005];
bool cmp(node x,node y){
	return x.ma1>y.ma1;
}
bool cmp2(node x,node y){
	return x.ma1<y.ma1;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","r",stdout);
	cin>>d;
	
	for(int i=1;i<=d;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j].ma1>>a[j].ma2>>a[j].ma3;	
			
		}
 	if(n[i]==2){
			sort(a+1,a+n[i]+1,cmp2);
		}else{
			sort(a+1,a+n[i]+1,cmp);
		}
		
		for(int z=1;z<=n[i];z++){
			int mx;
			mx=max(a[z].ma1,a[z].ma2);
			mx=max(mx,a[z].ma3);
			if(mx==a[z].ma1&&n1<=n[i]/2){
				n1++;
				ans+=a[z].ma1;
			}
			else if(mx==a[z].ma2&&n2<=n[i]/2){
				n2++;
				ans+=a[z].ma2;
			}
			else if(mx==a[z].ma3&&n3<=n[i]/2){
				n3++;
				ans+=a[z].ma3;
			}
		}
		c[i]=ans;
		ans=0;	
	}
	for(int i=1;i<=d;i++){
		cout<<c[i]<<endl;
	}
	return 0;
	
} 
