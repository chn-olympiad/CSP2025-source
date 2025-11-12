#include<bits/stdc++.h> 
using namespace std;
int t,n,ans;
int a1[100005],a2[100005],a3[100005];
int c1,c2,c3;
void find(int mem,int al,int c1,int c2,int c3){
	if(mem==n){
		if(c1<n/2){
//			cout<<c1;
//			cout<<1<<' '<<al+a1[n];
			ans=max(al+a1[n],ans);
//			cout<<':';
		}
		
		if(c2<n/2){
//			cout<<2<<' '<<al+a2[n];
			ans=max(al+a2[n],ans);
//			cout<<':';
		}
		
		if(c3<n/2){
//			cout<<3<<' '<<al+a3[n];
			ans=max(al+a3[n],ans);
//			cout<<':';
		}
		
		return;
	}
	if(c1<n/2){
//		c1++;
//		cout<<1;
		find(mem+1,al+a1[mem],c1+1,c2,c3);
//		c1--;
	}
	if(c2<n/2){
//		c2++;
//		cout<<2;
		find(mem+1,al+a2[mem],c1,c2+1,c3);
//		c2--;
	}
	if(c3<n/2){
//		c3++;
//		cout<<3;
		find(mem+1,al+a3[mem],c1,c2,c3+1);
//		c3--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
	cin>>t;
	while(t--){
		ans=0;
		c1=c2=c3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int c1=0,c2=0,c3=0;
		
//		for(int i=0;i<n;i++){
//			cout<<c1s[i+1]; 
//		}
//		cout<<'\n';
//		for(int i=0;i<n;i++){
//			cout<<c2s[i+1]; 
//		}
//		cout<<'\n';
//		for(int i=0;i<n;i++){
//			cout<<c3s[i+1]; 
//		}
//		cout<<'\n';
//		c1++;
//		cout<<1;
		find(2,a1[1],1,0,0);
//		cout<<'\n';
//		c1--;
//		c2++;
//		cout<<2;
		find(2,a2[1],0,1,0);
//		cout<<'\n';
//		c2--;
//		c3++;
//		cout<<3;
		find(2,a3[1],0,0,1);
//		cout<<'\n';
//		c3--;
		cout<<ans<<'\n';
	}
}
