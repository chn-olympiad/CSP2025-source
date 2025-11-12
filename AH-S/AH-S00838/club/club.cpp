#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],d[100010],maxa[100010],mind[100010],cnt0,cnt1,cnt2,dans,ans;
void ud(int i){
	if(a[i][0]>max(a[i][1],a[i][2])){
		maxa[i]=0;
		cnt0++;
		d[i]=a[i][0]-max(a[i][1],a[i][2]);
	}else if(a[i][1]>max(a[i][0],a[i][2])){
		maxa[i]=1;
		cnt1++;
		d[i]=a[i][1]-max(a[i][0],a[i][2]);
	}else if(a[i][2]>max(a[i][0],a[i][1])){
		maxa[i]=2;
		cnt2++;
		d[i]=a[i][2]-max(a[i][0],a[i][1]);
	}else{
		maxa[i]=3;
	}
}
int qy(int k,int cnt){
	int j=0,sum=0;
	for(int i=0;i<n;i++){
		if(maxa[i]==k){
			mind[j]=d[i];
			j++;
		}
	}
	sort(mind,mind+j);
	for(int i=0;i<cnt-n/2;i++) sum+=mind[i];
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int cs=0;cs<t;cs++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ud(i);
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		if(cnt0>n/2) dans=qy(0,cnt0);
		else if(cnt1>n/2) dans=qy(1,cnt1);
		else if(cnt2>n/2) dans=qy(2,cnt2);
		ans=ans-dans;
		cout<<ans<<endl;
		ans=dans=cnt0=cnt1=cnt2=0;
	}
	return 0;
}
