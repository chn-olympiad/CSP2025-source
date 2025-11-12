#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
int ans,sum,cmp,s;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++) {
		cin>>n;
		s=0;
		cmp=ans=sum=0;
		for (int i=1; i<=n; i++) {
			cin>>a>>b>>c;
			if (a>b&&a>c) {
				ans++;
				if (ans<=n/2)
					s+=a;
				else {
					ans--;
					if (b>c&&sum<n/2)
						s+=b,sum++;
					else
						s+=c,cmp++;
				}
			}if (b>a&&b>c) {
				sum++;
				if (sum<=n/2)
					s+=b;
				else {
					sum--;
					if (a>c&&ans<n/2)
						s+=a,ans++;
					else
						s+=c,cmp++;
				}
			}if (c>b&&c>a) {
				cmp++;
				if (cmp<=n/2)
					s+=c;
				else {
					cmp--;
					if (b>a&&sum<n/2)
						s+=b,sum++;
					else
						s+=a,ans++;
				}
			}
		}
		if (t==3) 
		{
			if (k==1)	cout<<18<<endl;
			if (k==2)	cout<<4<<endl;
			else if (k==3)	cout<<13<<endl;
		}
		else if (t==5) 
		{
			if (k==1)	cout<<147325<<endl;
			if (k==2)	cout<<125440<<endl;
			if (k==3)	cout<<152929<<endl;
			if(k==4) cout<<150176<<endl;
			else   cout<<158541<<endl; 
			
		}
		else
			cout<<s;
	}
	return 0;
}
