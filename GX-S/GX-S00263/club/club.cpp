#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,ans=0;
		cin>>n;
		int a[n]={},b[n]={},c[n]={};
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int cnt=n/2;
		int t1=0,t2=0,t3=0;
		for(int i=1;i<=cnt;i++)t1+=a[i];
		for(int i=1;i<=cnt;i++)t2+=b[i];
		for(int i=1;i<=cnt;i++)t3+=c[i];
		ans+=max(t1,max(t2,t3));
		if(t1<=t2&&t1<=t3){
			int cnt2=n/4;
			int t4=0,t5=0;
			for(int i=1;i<=cnt2+1;i++)t4+=b[i];
			for(int i=1;i<=cnt2+1;i++)t5+=c[i];
			ans+=max(t4,t5);
			if(t4<=t5)for(int i=1;i<=cnt2;i++)ans+=b[i];
			else for(int i=1;i<=cnt2;i++)ans+=c[i];
		}else if(t2<=t1&&t2<=t3){
			int cnt2=n/4;
			int t4=0,t5=0;
			for(int i=1;i<=cnt2+1;i++)t4+=a[i];
			for(int i=1;i<=cnt2+1;i++)t5+=c[i];
			ans+=max(t4,t5);
			if(t4<=t5)for(int i=1;i<=cnt2;i++)ans+=a[i];
			else for(int i=1;i<=cnt2;i++)ans+=c[i];
		}else{
			int cnt2=n/4;
			int t4=0,t5=0;
			for(int i=1;i<=cnt2+1;i++)t4+=a[i];
			for(int i=1;i<=cnt2+1;i++)t5+=b[i];
			ans+=max(t4,t5);
			if(t4<=t5)for(int i=1;i<=cnt2;i++)ans+=a[i];
			else for(int i=1;i<=cnt2;i++)ans+=b[i];
		}
		cout<<ans-4;
	}
	return 0;
}
