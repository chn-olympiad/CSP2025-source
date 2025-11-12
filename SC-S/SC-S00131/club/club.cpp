#include<bits/stdc++.h>
using namespace std;
struct dgz{
	int maxv1;int maxv2;
	int maxp1;int maxp2;
};
struct er{
	int v1;int v2;
};
er b[4];
dgz a[100010];
bool cmp(er a1,er a2){
	if(a1.v1<a2.v1){
		return true;
	}else if(a1.v1==a2.v1&&a1.v2<=a2.v2){
		return true;
	}else{
		return false;
	}
}
bool cmp1(dgz a1,dgz a2){
	if(a1.maxv2<a2.maxv2){
		return true;
	}else if(a1.maxv2==a2.maxv2&&a1.maxp1<=a2.maxp1){
		return true;
	}else{
		return false;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;int num[4]={0};long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[1].v1>>b[2].v1>>b[3].v1;
			b[1].v2=1;b[2].v2=2;b[3].v2=3;
			sort(b+1,b+3+1,cmp);
			a[i].maxv1=b[3].v1;a[i].maxp1=b[3].v2;num[b[3].v2]++;
			a[i].maxv2=b[3].v1-b[2].v1;sum+=a[i].maxv1;
		}
		int maxp=0;int maxv=0;
		for(int i=1;i<=3;i++){
			if(num[i]>maxv){
				maxv=num[i];
				maxp=i;
			}
		}
		if(maxv<=(n/2)){
			cout<<sum<<endl;
		}else{
			sort(a+1,a+n+1,cmp1);
			int cha=maxv-(n/2);
			for(int i=1;i<=n;i++){
				if(a[i].maxp1==maxp&&cha>0){
					cha--;
					sum-=a[i].maxv2;
				}else if(cha==0){
					break;
				}
			}
			cout<<sum<<endl;
		}
	}
	
	return 0;
 } 