#include<bits/stdc++.h>
using namespace std;
int a_1[100001];
int a_2[100001];
int a_3[100001];
int inl[100001];
bool cmp(int a,int b){return a>b;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,x,m1=0,m2=0,m3=0,ans=0;cin>>n;x=n/2;
		bool b1=1,b2=1,b3=1;
		for(int i=0;i<n;i++){
		 	cin>>a_1[i]>>a_2[i]>>a_3[i];
		}
		for(int i=0;i<n;i++){
			if(b1==0&&b2==0&&b3==0)break;
			int o=max((!b1?0:a_1[i]),max((!b2?0:a_2[i]),(!b3?0:a_3[i])));
			ans+=o;
			if(o==a_1[i])m1++;
			if(o==a_2[i])m2++;
			if(o==a_3[i])m3++;
			if(m1==x)b1=0;
			if(m2==x)b2=0;
			if(m3==x)b3=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
