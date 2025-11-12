#include<bits/stdc++.h>
using namespace std;
int t;
struct dom{
	int idx,a,b,c;
};
struct don{
	int idx,m;
};
bool cmp (don a,don b){
	return a.m>b.m;
}
	
void solve(){

	int sum=0,temp1,temp2,temp3,cnt1=1,cnt2=1,cnt3=1;
	don a1[10010],b1[10010],c1[10010];
	dom a[10010];
	bool b[10010];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].idx=i;
		a1[i].idx=i;
		b1[i].idx=i;
		c1[i].idx=i;
		a1[i].m=a[i].a;
		b1[i].m=a[i].b;
		c1[i].m=a[i].c;
	}
	sort(a1+1,a1+n+1);
	sort(b1+1,b1+n+1);
	sort(c1+1,c1+n+1);
	for(int i=1;i<=n;i++){
		if(a1[cnt1].m>=b1[cnt2].m&&a1[cnt1].m>=c1[cnt3].m&&b[a1[cnt1].idx]!=1&&temp2<=n/2){	
			sum+=a1[cnt1].m;
			temp1++;
			b[a1[cnt1].idx]=1;
		} 	
	
		else if(b1[cnt2].m>=a1[cnt1].m&&b1[cnt2].m>=c1[cnt3].m&&b[b1[cnt2].idx]!=1&&temp2<=n/2){	
			sum+=b1[cnt2].m;
			temp2++;
			b[b1[cnt2].idx]=1; 	
		}
		else if(c1[cnt1].m>=b1[cnt2].m&&c1[cnt1].m>=a1[cnt3].m&&b[c1[cnt1].idx]!=1&&temp3<=n/2){	
			sum+=c1[cnt3].m;
			temp3++;
			b[c1[cnt3].idx]=1; 	
		}
	}
	cout<<sum<<endl;
}
int main(){
	while(t--){
		solve();
	}
	return 0;
}
