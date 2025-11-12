#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
struct node{
	ll s1,s2,s3;
}p[N];
ll t,n,cnt,t1,t2,t3;

bool cmp(node a,node b){
	return max(a.s2-a.s1,a.s3-a.s1)<max(b.s2-b.s1,b.s3-b.s1);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=t1=t2=t3=0;
		ll ot=n/2,bg=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].s1>>p[i].s2>>p[i].s3;
			if(p[i].s1>p[i].s2&&p[i].s1>p[i].s3)t1++;
			if(p[i].s2>p[i].s1&&p[i].s2>p[i].s3)t2++;
			if(p[i].s3>p[i].s2&&p[i].s3>p[i].s1)t3++;
		}
		if(t2>ot)
		for(int i=1;i<=n;i++)
		swap(p[i].s1,p[i].s2);
		else if(t3>ot)
		for(int i=1;i<=n;i++)
		swap(p[i].s1,p[i].s3);
		t1=max(max(t1,t2),t3);
		if(t1>ot){
			for(int i=1;i<=t1+1;i++){
				while(bg<=n&&p[bg].s1<=p[bg].s2||p[bg].s1<=p[bg].s3)bg++;
				if(bg<=n)
				swap(p[i],p[bg]);
				bg++;
			}
			sort(p+1,p+t1+1,cmp);
			for(int i=1;i<=ot;i++)
			cnt+=p[i].s1;
			for(int i=ot+1;i<=n;i++)
			cnt+=max(p[i].s2,p[i].s3);
		}
		else
		for(int i=1;i<=n;i++)
		cnt+=max(max(p[i].s1,p[i].s2),p[i].s3);
		cout<<cnt<<endl;
	}
	return 0;
} 