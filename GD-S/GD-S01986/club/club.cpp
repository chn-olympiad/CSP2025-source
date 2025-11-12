#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
}man[100005];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.a-x.b>y.a-y.b;
}
long long t,n,ans;bool flag1,flag2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0,flag1=flag2=0;
		
		cin>>n;long long ned=n/2;
		for(int i=1;i<=n;i++){
			
			cin>>man[i].a>>man[i].b>>man[i].c;
			if(man[i].c)flag1=1;//==0,b
			if(man[i].b||man[i].c)flag2=1;//==0,a
		}
		if(!flag2){
			sort(man+1,man+n+1,cmp1);
			for(int i=1;i<=ned;i++){
				ans+=man[i].a;
			}
			cout<<ans<<endl;
		}else if(!flag1){
			sort(man+1,man+n+1,cmp2);
			for(int i=1;i<=ned;i++){
				ans+=man[i].a;
			}
			for(int i=ned+1;i<=n;i++){
				ans+=man[i].b;
			}
			cout<<ans<<endl;
		}else if(n==2){
			int oo[105][105];
			memset(oo,0,sizeof oo);
			int ma=max(man[1].a,max(man[1].b,man[1].c));
			int min1=min(man[1].a,min(man[1].b,man[1].c));
			int mid1=man[1].b+man[1].a+man[1].c-ma-min1;
			int ma2=max(man[2].a,max(man[2].b,man[2].c));
			int min2=min(man[2].a,min(man[2].b,man[2].c));
			int mid2=man[2].b+man[2].a+man[2].c-ma2-min2;
			if((ma==man[1].a&&ma2==man[2].a)||(ma==man[1].b&&ma2==man[2].b)||(ma==man[1].c&&ma2==man[2].c))
				cout<<max(ma2+mid1,ma+mid2);
			else cout<<ma+ma2;
		}
	
		
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
} 
