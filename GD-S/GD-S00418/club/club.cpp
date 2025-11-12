#include<bits/stdc++.h>
using namespace std;
int t,ans,c_1,c_2,c_3;
struct Node{
	int v1,v2,v3,fir,sec;
};
bool cmp(Node x,Node y){
	return max(max(x.v1,x.v2),x.v3)>max(max(y.v1,y.v2),y.v3);
}
bool cmp1(Node x,Node y){
	return x.fir-x.sec>y.fir-y.sec;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		Node w[100005];
		cin>>n;
		for(int i=1;i<=n;i++) cin>>w[i].v1>>w[i].v2>>w[i].v3;
		sort(w+1,w+n+1,cmp);
		ans=0,c_1=0,c_2=0,c_3=0;
		for(int i=1;i<=n;i++){
			int a=max(max(w[i].v1,w[i].v2),w[i].v3);
			if(a==w[i].v1) c_1++;
			else if(a==w[i].v2) c_2++;
			else c_3++;
			ans+=a;
		}
		int m=n/2;
		if(c_1<=m&&c_2<=m&&c_3<=m){
			cout<<ans<<endl;
		}
		else{
			int in=1;
			if(c_2>m) in=2;
			if(c_3>m) in=3;
			for(int i=1;i<=n;i++){
				if(in==1){
					w[i].fir=w[i].v1;
					w[i].sec=max(w[i].v2,w[i].v3);
				}
				if(in==2){
					w[i].fir=w[i].v2;
					w[i].sec=max(w[i].v1,w[i].v3);
				}
				if(in==3){
					w[i].fir=w[i].v3;
					w[i].sec=max(w[i].v2,w[i].v1);
				}
			}
			ans=0;
			for(int i=1;i<=n;i++) ans+=w[i].sec;
			sort(w+1,w+n+1,cmp1);
			for(int i=1;i<=m;i++) ans+=w[i].fir-w[i].sec;
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
