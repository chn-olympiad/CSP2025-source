//GZ-S00491 贵阳市南明区双龙华麟学校 霍玥霓
//特A,B 
#include<bits/stdc++.h>
using namespace std;
int t;
struct Node{
	int n1;
	int n2;
	int n3;
};
int cmp(Node x,Node y){
	if(x.n1!=y.n1) return x.n1>y.n1;
	else if(x.n2!=y.n2) return x.n2<y.n2;
	else return x.n3>y.n3;
}
int check(int a,int b,int c,int &f_){
	if(a >= b){
		if(a >= c){
			f_=1;
			return a;
		}else {
			f_=3;
			return c;
		}
	}else {
		if(b>=c){
			f_=2;
			return b;
		}else {
			f_=3;
			return c;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		int flag=-1;
		cin>>n;
		Node a[n+2];
		for(int i=1;i<=n;i++){
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			if(a[i].n1 !=0 && (a[i].n2==0&&a[i].n3==0)) flag=1;
			else if((a[i].n1!=0&&a[i].n2!=0) && a[i].n3 == 0) flag=0;
		}
		sort(a+1,a+n+1,cmp);
		if(flag==1){
			int ans=0;
			for(int i=1;i<=n/2;i++){
			    ans+=a[i].n1;
			}
			cout<<ans<<endl;
		}
		else if(flag==0){
			int ans=0;
			for(int i=1;i<=n/2;i++){
			    ans+=a[i].n1;
			}
			for(int i=n/2+1;i<=n/2+n/2;i++){
				ans+=a[i].n2;
			}
			cout<<ans<<endl;
		}else {
			int ans=0,c1=0,c2=0,c3=0,f_=0;
			for(int i=1;i<=n;i++){
				int temp=check(a[i].n1,a[i].n2,a[i].n3,f_);
				if(f_==1 && c1<n/2) ans+=temp,c1++;
				else if(f_==2 && c2<n/2) ans+=temp,c2++;
				else if(f_==3 && c3<n/2) ans+=temp,c3++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
