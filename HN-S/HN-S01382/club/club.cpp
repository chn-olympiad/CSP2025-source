#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;

int w,n,s1,s2,s3;
int sum;

struct cwz{
	int myd1,myd2,myd3,bx,mx;
}an[N];

int cmd(cwz a,cwz b){
	if(a.myd1>b.myd1) return 1;
	return 0;
}

int cmd2(cwz a,cwz b){
	if(a.myd2>b.myd2) return 1;
	return 0;
}

int cmd3(cwz a,cwz b){
	if(a.myd3>b.myd3) return 1;
	return 0;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);	
	cin>>w;
	while(w--){
		cin>>n;
		s1=s2=s3=n/2;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>an[i].myd1>>an[i].myd2>>an[i].myd3;
			an[i].mx=max(an[i].myd1,max(an[i].myd2,an[i].myd3));
			an[i].bx=i;
		}
		if(n==2){
			cout<<max(an[1].myd1+an[2].myd2,max(an[1].myd1+an[2].myd3,max(an[1].myd2+an[2].myd1,max(an[1].myd2+an[2].myd3,max(an[1].myd3+an[2].myd1,an[1].myd3+an[2].myd2)))))<<"\n";
			continue;
		} else {
			sort(an+1,an+1+n,cmd);
			for(int i=1;i<=n;i++){
				if(an[i].myd1==an[i].mx && an[i].bx && s1){
					s1--;
					sum+=an[i].mx;
					an[i].bx=0;
				}
			}
			sort(an+1,an+1+n,cmd2);
			for(int i=1;i<=n;i++){
				if(an[i].myd2==an[i].mx && an[i].bx && s2){
					s2--;
					sum+=an[i].mx;
					an[i].bx=0;
				}
			}
			sort(an+1,an+1+n,cmd3);
			for(int i=1;i<=n;i++){    
				if(an[i].myd3==an[i].mx && an[i].bx && s3){
					s3--;
					sum+=an[i].mx;
					an[i].bx=0;
				}
			}
		}
		
		cout<<sum<<"\n";
	}
	return 0;
}
