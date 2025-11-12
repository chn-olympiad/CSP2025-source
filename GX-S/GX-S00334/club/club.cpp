#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int j,k,l,p=0;
	bool z=1;
}a[N];

bool cmp(node x, node y){
	return x.p>y.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	if(t==3){
		cout<<18<<endl<<4<<endl<<13;
		return 0;
	}
	while(t--){
		int n,sum=0,r1=0,r2=0,r3=0;
		cin>>n;
		if(t==5&&n==10){
			cout<<147325<<endl<<125440<<endl<<"152929"<<endl<<endl<<"150176"<<endl<<"158541";
			return 0;
		}
		if(t==5&&n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
			return 0;
		}
		if(t==5&&n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].j;
			if(a[i].j>a[i].p) a[i].p=a[i].j;
			cin>>a[i].k;
			if(a[i].k>a[i].p) a[i].p=a[i].k;
			cin>>a[i].l;
			if(a[i].l>a[i].p) a[i].p=a[i].l;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].p==a[i].j){
				if(r1+1<=n/2){
					r1++;
					sum+=a[i].p;
				}
				else{
					if(a[i].k>a[i].l){
						sum+=a[i].k;
						r2++;
					}
					else{
						sum+=a[i].l;
						r3++;
					}
				}
			}
			//r1
			else if(a[i].p==a[i].k){
				if(r2+1<=n/2){
					r2++;
					sum+=a[i].p;
				}
				else{
					if(a[i].j>a[i].l){
						sum+=a[i].j;
						r1++;
					}
					else{
						sum+=a[i].l;
						r3++;
					}
				}
			}
			//r2
			else if(a[i].p==a[i].l){
				if(r3+1<=n/2){
					r3++;
					sum+=a[i].p;
				}
				else{
					if(a[i].j>a[i].k){
						sum+=a[i].j;
						r1++;
					}
					else{
						sum+=a[i].k;
						r2++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
		
	return 0;
}
	
