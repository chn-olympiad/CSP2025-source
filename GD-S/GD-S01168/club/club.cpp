#include<bits/stdc++.h>
using namespace std;
int n,a[10001][3],cha[10001],t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	cin>>n;
	int ans=0,st1=0,st2=0,st3=0,mr=n/2;
	for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cha[i]=max(abs(a[i][1]-a[i][2]),max(abs(a[i][2]-a[i][3]),abs(a[i][1]-a[i][3])));
	}
	int st[4]={};
	int temp[10001];
	int js=1;
	for(int i=1;i<=n;i++){
		int num=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=num;
		if(st[1]>mr||st[2]>mr||st[3]>mr){
			temp[js++]=cha[i];
		}else{
			if(num==a[i][1])st[1]++;
			else if(num==a[i][2])st[2]++;
			else st[3]++;
		}
	}
	int mans=0;
	sort(temp+1,temp+js+1);
	for(int i=1;i<=3;i++){
		if(st[i]>mr)mans=st[i]-mr;
	}
	for(int i=1;i<=mans;i++){
		ans-temp[i];
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
	}
}
