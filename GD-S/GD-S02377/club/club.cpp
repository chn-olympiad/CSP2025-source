#include <bits/stdc++.h>
using namespace std;
int t;
struct Student{
	int aa,b,c,maxn,id,sum,minn;
};
long long sum;
bool cmp(Student x,Student y){
	return x.minn<=y.minn;
	return x.maxn>y.maxn;
}
Student a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num[5]={0,0,0,0};
		sum=0;
		bool flag[5]={true,true,true,true};
		for(int i=1;i<=n;i++){
			cin>>a[i].aa>>a[i].b>>a[i].c;
			a[i].sum=a[i].aa+a[i].b+a[i].c;
			if(a[i].aa>=max(a[i].b,a[i].c)){
				a[i].maxn=a[i].aa;
				a[i].id=1; 
				a[i].minn=min(a[i].b,a[i].c);
			} 
			else if(a[i].b>max(a[i].aa,a[i].c)){
				a[i].maxn=a[i].b;  
				a[i].id=2;
				a[i].minn=min(a[i].aa,a[i].c);
			} 
			else if(a[i].c>max(a[i].b,a[i].aa)){
				a[i].maxn=a[i].c;
				a[i].id=3;
				a[i].minn=min(a[i].b,a[i].aa);
			} 
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(flag[a[i].id]){
				sum+=a[i].maxn;
				num[a[i].id]++;
			}
			else{
				sum+=a[i].sum-a[i].maxn-a[i].minn;
			}
			if(num[a[i].id]==n/2) flag[a[i].id]=false;
		}
		cout<<sum<<endl;
	}
	return 0;
}
