#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int _,n;
struct node{
	int num1,num2,num3,cho;
}dt[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		int cnt[4]={0,0,0,0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int x=max(max(a,b),c),y,z=min(min(a,b),c);
			if(a!=x && a!=z) y=a;
			else if(b!=x && b!=z) y=b;
			else y=c;
			dt[i].num1=x;
			dt[i].num2=y;
			dt[i].num3=z;
			if(x==a) dt[i].cho=1;
			else if(x==b) dt[i].cho=2;
			else dt[i].cho=3;
			cnt[dt[i].cho]++;
		}
		int index=0,cont=0,s[100001]={0};
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) index=i;
		}
		for(int i=1;i<=n;i++) ans+=dt[i].num1;
		if(index==0){
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(dt[i].cho==index) s[++cont]=dt[i].num1-dt[i].num2;
		}
		sort(s+1,s+1+cont);
		int g=1;
		while(cnt[index]>n/2){
			ans-=s[g];
			g++;
			cnt[index]--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
