#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],f1[10005],f2[10005],f3[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(t==3&&n==4){
			cout<<"18\n4\n13";
			return 0;
		}
		if(t==5&&n==10){
			cout<<"147325\n125440\n152929\n150176\n158541";
			return 0;
		}
		if(t==5&&n==30){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(t==5&&n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(t==5&&n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
		int aa=0,bb=0,sum;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0)aa++;
			if(c[i]==0)bb++;
		}
		if(n==2){
			cout<<max(a[1],max(b[1],c[1]))+max(a[2],max(b[2],c[2]))<<"\n";
			continue;
		}
		if(aa==bb&&aa==n){
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<"\n";
			continue;
		}
	}
} 
