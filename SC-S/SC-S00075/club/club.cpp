#include<bits/stdc++.h>
using namespace std;
int n,t,cnt1,cnt2,cnt3,s1[200005],s2[200005],s3[200005];
long long sum=0;
struct node{
	int a,b,c;
}e[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt1=0,cnt2=0,cnt3=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
				cnt1++;sum+=e[i].a;
				s1[cnt1]=e[i].a-max(e[i].b,e[i].c);
			}
			else if(e[i].b>=e[i].a&&e[i].b>=e[i].c){
				cnt2++;sum+=e[i].b;
				s2[cnt2]=e[i].b-max(e[i].a,e[i].c);
			}
			else if(e[i].c>=e[i].b&&e[i].c>=e[i].a){
				cnt3++;sum+=e[i].c;
				s3[cnt3]=e[i].c-max(e[i].b,e[i].a);
			}
		}
//		cout<<sum<<endl<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
		if(cnt1>n/2){
			sort(s1+1,s1+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++){
				sum-=s1[i];
			}
		}
		else if(cnt2>n/2){
			sort(s2+1,s2+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++){
				sum-=s2[i];
			}
		}
		else if(cnt3>n/2){
			sort(s3+1,s3+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++){
				sum-=s3[i];
			}
		} 
		cout<<sum<<endl;
	}
	return 0;
}