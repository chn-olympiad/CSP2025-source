#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct node{
	int a1,a2,a3;
}q[MAXN];
int t;
bool cmp1(node x,node y){
	return max(x.a1,max(x.a2,x.a3))>max(y.a1,max(y.a2,y.a3));
}
bool cmp2(node x,node y){
	return max(x.a1,x.a3)>max(y.a1,y.a3);
}
bool cmp3(node x,node y){
	return max(x.a2,x.a3)>max(y.a2,y.a3);
}
bool cmp4(node x,node y){
	return max(x.a1,x.a2)>max(y.a1,y.a2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	while(t--){
		long long ans=0;
		bool flag1=false,flag2=false,flag3=false;
		int n,num1=0,num2=0,num3=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>q[i].a1>>q[i].a2>>q[i].a3;
		sort(q+1,q+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(num1==n/2&&flag1==false){
				sort(q+1+i,q+1+n,cmp3);
				flag1=true;
			}else if(num2==n/2&&flag2==false){
				sort(q+1+i,q+1+n,cmp2);
				flag2=true;
			}else if(num3==n/2&&flag3==false){
				sort(q+1+i,q+1+n,cmp4);
				flag3=true;
			}
			if(q[i].a1>q[i].a2&&q[i].a1>q[i].a3&&num1<n/2){
				num1++;
				ans+=q[i].a1;
			}else if(q[i].a2>q[i].a1&&q[i].a2>q[i].a3&&num2<n/2){
				num2++;
				ans+=q[i].a2;
			}else if(q[i].a3>q[i].a1&&q[i].a3>q[i].a2&&num3<n/2){
				num3++;
				ans+=q[i].a3;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//Turns No.33550337
